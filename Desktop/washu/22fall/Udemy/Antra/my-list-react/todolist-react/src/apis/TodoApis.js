const baseURL = "http://localhost:3000/todos";

const createTodo = (newTodo) => {
  return fetch(baseURL, {
    method: "POST",
    body: JSON.stringify(newTodo),
    headers: { "Content-Type": "application/json" },
  }).then((res) => res.json());
};

const deleteTodo = (id) => {
  return fetch(`${baseURL}/${id}`, {
    method: "DELETE",
  }).then((res) => res.json());
};

const getTodos = () => {
  return fetch("http://localhost:3000/todos").then((res) => res.json());
};

const updateTodo = (todo) => {
  return fetch(`${baseURL}/${todo.id}`, {
    method: "PATCH",
    body: JSON.stringify(todo),
    headers: { "Content-Type": "application/json" },
  }).then((res) => res.json());
};

export { createTodo, deleteTodo, getTodos, updateTodo };
