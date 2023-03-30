import React from "react";
import { getTodos, deleteTodo, createTodo, updateTodo } from "../apis/TodoApis";

export const withTodos = (WrappedComponent) => {
  return class NewComponent extends React.Component {
    state = {
      todos: [],
      isEdit: null,
    };

    handleSubmit = (content) => {
      console.log(content);
      const newTodo = {
        content: content,
        completed: false,
      };
      createTodo(newTodo).then((todo) => {
        this.setState((prev) => {
          return {
            todos: [...prev.todos, todo],
          };
        });
      });
    };

    handleDelete = (id) => {
      deleteTodo(id).then(() => {
        this.setState({
          todos: this.state.todos.filter((todo) => id !== todo.id),
        });
      });
    };

    handleComplete = (todo) => {
      console.log("complete todo");
      updateTodo({ ...todo, completed: !todo.completed }).then((res) => {
        this.setState({
          todos: this.state.todos.map((item) => {
            if (item.id === res.id) {
              return { ...res };
            } else {
              return item;
            }
          }),
        });
      });
    };

    handleEdit = (id) => {
      this.setState({
        isEdit: id,
      });
    };

    handleSave = (todo) => {
      updateTodo(todo).then((res) => {
        this.setState({
          isEdit: null,
          todos: this.state.todos.map((item) => {
            if (item.id === res.id) {
              return res;
            } else {
              return item;
            }
          }),
        });
      });
    };

    componentDidMount() {
      getTodos().then((todos) => {
        this.setState({
          todos,
        });
      });
    }

    render() {
      return (
        <WrappedComponent
          todos={this.state.todos}
          handleDelete={this.handleDelete}
          handleSubmit={this.handleSubmit}
          handleComplete={this.handleComplete}
          handleEdit={this.handleEdit}
          isEdit={this.state.isEdit}
          handleSave={this.handleSave}
        />
      );
    }
  };
};
