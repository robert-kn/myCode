"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const todoItem_1 = require("./todoItem");
const todoCollections_1 = require("./todoCollections");
let todos = [
    new todoItem_1.TodoItem(1, "buy flowers"),
    new todoItem_1.TodoItem(2, "get dinner"),
    new todoItem_1.TodoItem(3, "collect tickets"),
    new todoItem_1.TodoItem(4, "call mum", true)
];
let collection = new todoCollections_1.TodoCollection("Robert", todos);
console.clear();
console.log(`${collection.userName}'s to do list`);
let newId = collection.addTodo("go to the gym");
let todoItem = collection.getTodoById(newId);
todoItem.printDetails();
console.log(JSON.stringify(todoItem));
