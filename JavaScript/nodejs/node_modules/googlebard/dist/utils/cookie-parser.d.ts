import { DbSet } from "dbcontext";
import Cookie from "../models/cookie";
declare function CookieParser(setCookies: any, cookies: DbSet<Cookie>): void;
export default CookieParser;
