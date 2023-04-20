import { DbContext, DbSet } from "../dist/index.js";

class AppDbContext extends DbContext {
  constructor() {
    super();
  }

  users = new DbSet("users");
  books = new DbSet("books");
}

const appDbContext = new AppDbContext();
await appDbContext.WaitForLoad();

let users = appDbContext.users.ToArray();
console.log(users);

let books = appDbContext.books.ToArray();
console.log(books);

// Add a new user
appDbContext.users.Add({
  id: 1,
  name: "John Doe",
  age: 25,
});

// Add a new book
appDbContext.books.Add({
  id: 1,
  name: "The Lord of the Rings",
});

console.log(appDbContext.users.ToArray());
console.log(appDbContext.books.ToArray());