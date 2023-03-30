import React from "react";
import { getTodos } from "../../apis/TodoApis";
import { withTodos } from "../../hoc/withTodos";

class Dashboard extends React.Component {
  state = {
    totalTodoCount: 0,
    totalCompletedTodoCount: 0,
  };

  render() {
    const { todos } = this.props;
    const totalTodoCount = todos.length;
    const totalCompletedTodoCount = todos.filter(
      (todo) => todo.completed === true
    ).length;
    return (
      <div>
        <h1>DashBoard</h1>
        <h4>Total Todo Count: {totalTodoCount}</h4>
        <h4>Total Completed Todo Count: {totalCompletedTodoCount}</h4>
      </div>
    );
  }

  // componentDidMount() {
  //   getTodos().then((todos) => {
  //     this.setState({
  //       totalTodoCount: todos.length,
  //       totalCompletedTodoCount: todos.filter((todo) => todo.completed === true)
  //         .length,
  //     });
  //   });
  // }
}

export default withTodos(Dashboard);
