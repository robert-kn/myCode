import { TodoItem } from "./todoItem";
import { TodoCollection } from "./todoCollections";

let todos = [
    new TodoItem(1, "buy flowers"), 
    new TodoItem(2, "get dinner"), 
    new TodoItem(3, "collect tickets"), 
    new TodoItem(4, "call mum", true)];

let collection: TodoCollection = new TodoCollection("Robert", todos);

console.clear();
console.log(`${collection.userName}'s to do list`);

let newId: number = collection.addTodo("go to the gym");
let todoItem: TodoItem = collection.getTodoById(newId);
todoItem.printDetails();
console.log(JSON.stringify(todoItem));