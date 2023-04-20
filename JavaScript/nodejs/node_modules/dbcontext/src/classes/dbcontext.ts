import fs from "fs";
import DbSet from "../classes/db-set.js";
import Options from "../models/options.js";
import Wait from "../utils/wait.js";

class DbContext {
	private options: Options;
	private path = "./db.json";
	private intervalId: NodeJS.Timeout;
	private loaded: boolean = false;

	constructor(path: string = "./db.json", options?: Options) {
		this.options = {
			saveInterval: options?.saveInterval || 1000 * 5,
		};
		this.path = path;
		this.load();
		this.intervalId = setInterval(async () => {
			if (!this.loaded) return;
			await Wait(100);
			this.save();
		}, this.options.saveInterval);
	}

	public async WaitForLoad() {
		while (!this.loaded) {
			await Wait(100);
		}
	}

	private getTmpPath(path: string): string {
		if (path.indexOf(".") === -1) {
			return `${path}.tmp`;
		}

		const pathParts = path.split(".");
		const extension = pathParts.pop();
		const newPath = `${pathParts.join(".")}.tmp.${extension}`;
		return newPath;
	}

	private isJSON(str: string): boolean {
		try {
			JSON.parse(str);
		} catch (e) {
			return false;
		}
		return true;
	}

	private async load() {
		let tmpFilePath = this.getTmpPath(this.path);
		if (fs.existsSync(tmpFilePath)) {
			let tmpFileData = await fs.promises.readFile(tmpFilePath, "utf8");
			if (this.isJSON(tmpFileData)) {
				await fs.promises.rename(tmpFilePath, this.path);
				console.log("Recovered from a crash.");
			}
		}
		if (!fs.existsSync(this.path)) {
			this.loaded = true;
			return;
		}
		let data = await fs.promises.readFile(this.path, "utf8");
		if (!this.isJSON(data)) {
			this.loaded = true;
			return;
		}
		let json = JSON.parse(data);

		for (let key in json) {
			this[key] = new DbSet(json[key].name, json[key].rows);
		}

		await Wait(1000);
		this.loaded = true;
	}

	public async save() {
		let tmpFilePath = this.getTmpPath(this.path);
		let result: any = {};
		for (let key in this) {
			if (this[key] instanceof DbSet) {
				result[key] = this[key];
			}
		}
		await fs.promises.writeFile(tmpFilePath, JSON.stringify(result, null, 4));
		await fs.promises.rename(tmpFilePath, this.path);
	}

	public async close() {
		clearInterval(this.intervalId);
		await this.save();
	}
}

export default DbContext;
