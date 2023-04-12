import { Fragment } from 'react';
import Header from './Header';
import "./Header.module.css"

const Layout = (props) => {
    return (
        <Fragment>
            <Header />
            <main>{props.children}</main>
        </Fragment>
    );
};

export default Layout;