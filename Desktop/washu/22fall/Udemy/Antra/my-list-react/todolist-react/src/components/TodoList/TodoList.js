import React from "react";
import TodoItem from "./TodoItem/TodoItem";
// import {
//   createTodo,
//   deleteTodo,
//   getTodos,
//   updateTodo,
// } from "../../apis/TodoApis";

import "./TodoList.css";
import { withTodos } from "../../hoc/withTodos";

class TodoList extends React.Component {
  state = {
    // todos: [],
    inputText: "",
    // isEdit: null,
  };

  handleInputChange = (e) => {
    this.setState({
      inputText: e.target.value,
    });
  };

  handleSubmit = () => {
    // const newTodo = {
    //   content: this.state.inputText,
    //   completed: false,
    // };
    // createTodo(newTodo).then((todo) => {
    //   this.setState((prev) => {
    //     return {
    //       todos: [...prev.todos, todo],
    //       inputText: "",
    //     };
    //   });
    // });
    this.props.handleSubmit(this.state.inputText);
    this.setState({
      inputText: "",
    });
  };

  // handleDelete = (id) => {
  //   deleteTodo(id).then(() => {
  //     this.setState({
  //       todos: this.state.todos.filter((todo) => id !== todo.id),
  //     });
  //   });
  // };

  // handleComplete = (todo) => {
  //   console.log("complete todo");
  //   updateTodo({ ...todo, completed: !todo.completed }).then((res) => {
  //     this.setState({
  //       todos: this.state.todos.map((item) => {
  //         if (item.id === res.id) {
  //           return { ...res };
  //         } else {
  //           return item;
  //         }
  //       }),
  //     });
  //   });
  // };

  // handleEdit = (id) => {
  //   this.setState({
  //     isEdit: id,
  //   });
  // };

  // handleSave = (todo) => {
  //   updateTodo(todo).then((res) => {
  //     this.setState({
  //       isEdit: null,
  //       todos: this.state.todos.map((item) => {
  //         if (item.id === res.id) {
  //           return res;
  //         } else {
  //           return item;
  //         }
  //       }),
  //     });
  //   });
  // };

  // componentDidUpdate() {
  //   console.log(this.state.inputText);
  // }

  render() {
    const { todos, handleDelete, handleComplete, handleEdit, isEdit, handleSave } = this.props;
    const pendingTodos = todos.filter((todo) => todo.completed === false);
    const completedTodos = todos.filter((todo) => todo.completed === true);
    // console.log(pendingTodos, completedTodos);
    return (
      <div className="todolist">
        <h1>TodoList</h1>
        <div className="todolist-form">
          <input
            className="todolist-input"
            onChange={(e) => this.handleInputChange(e)}
            value={this.state.inputText}
          />
          <button className="btn submit-btn" onClick={this.handleSubmit}>
            submit
          </button>
        </div>
        <div className="todolist-lists">
          <ul className="todolist-list">
            <h4>Pending</h4>
            {pendingTodos.length !== 0
              ? pendingTodos.map((todo) => (
                <TodoItem
                  key={todo.id}
                  todo={todo}
                  onDelete={handleDelete}
                  onComplete={handleComplete}
                  onEdit={handleEdit}
                  onSave={handleSave}
                  isEdit={todo.id === isEdit}
                />
              ))
              : "no task to display"}
          </ul>
          <ul className="todolist-list">
            <h4>Completed</h4>

            {completedTodos.length !== 0
              ? completedTodos.map((todo) => (
                <TodoItem
                  key={todo.id}
                  todo={todo}
                  onDelete={handleDelete}
                  onComplete={handleComplete}
                  onEdit={handleEdit}
                  onSave={handleSave}
                  isEdit={todo.id === isEdit}
                />
              ))
              : "no task to display"}
          </ul>
        </div>
      </div>
    );
  }

  // componentDidMount() {
  //   getTodos().then((todos) => {
  //     this.setState({
  //       todos,
  //     });
  //   });
  // }
}

export default withTodos(TodoList);
