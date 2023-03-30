import React from "react";
import "./App.css";
import TodoList from "./components/TodoList/TodoList";
import Layout from "./components/Layout/Layout";
import Dashboard from "./components/Dashboard/Dashboard";

class App extends React.Component {
  state = {
    activePage: "Dashboard",
  };

  handleChangeActivePage = (newActivePage) => {
    console.log(newActivePage);
    this.setState({
      activePage: newActivePage,
    });
  };

  render() {
    let content = null;
    switch (this.state.activePage) {
      case "Dashboard":
        content = <Dashboard />;
        break;
      case "TodoList":
        content = <TodoList />;
        break;
      default:
        break;
    }

    return (
      <Layout handleChangeActivePage={this.handleChangeActivePage}>
        {content}
      </Layout>
    );
  }
}

export default App;
