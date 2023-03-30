import React from "react";
import "./Header.css";

class Header extends React.Component {
  render() {
    const { handleChangeActivePage } = this.props;

    return (
      <ul className="nav">
        <h1>Header</h1>
        <li onClick={() => handleChangeActivePage("Dashboard")}>DashBoard</li>
        <li onClick={() => handleChangeActivePage("TodoList")}>TodoList</li>
      </ul>
    );
  }
}

export default Header;
