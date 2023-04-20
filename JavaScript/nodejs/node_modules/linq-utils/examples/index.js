import Linq from "../dist/index.js";

let numbers = [1, 2, 3, 4, 5];

let linq = new Linq(numbers);

let result = linq
  .Where(x => x % 2 === 0)
  .Select(x => x * 2)
  .ToArray();

console.log(result); // [4, 8]