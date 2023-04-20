import Options from "../models/options.js";
declare class Bard {
    private axios;
    private db;
    private cookies;
    constructor(cookie: string, options?: Options);
    private waitForLoad;
    private addConversation;
    private getConversationById;
    resetConversation(id?: string): void;
    private ParseResponse;
    private GetRequestParams;
    ask(prompt: string, conversationId?: string): Promise<any>;
    askStream(data: (arg0: string) => void, prompt: string, conversationId?: string): Promise<any>;
    private send;
}
export default Bard;
