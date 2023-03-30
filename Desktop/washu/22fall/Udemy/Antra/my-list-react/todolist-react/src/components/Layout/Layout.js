import React from "react";
import Header from "../Header/Header";

class Layout extends React.Component {
  render() {
    const { handleChangeActivePage } = this.props;
    return (
      <>
        <header>
          <Header handleChangeActivePage={handleChangeActivePage} />
        </header>
        <main className="content">{this.props.children}</main>
      </>
    );
  }
}

export default Layout;
