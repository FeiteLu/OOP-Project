import classes from './Header.module.css';
import { Link } from 'react-router-dom';

const Header = (props) => {
    return (

        <header className={classes.header}>
            <h1>SearchBook</h1>
            <div className='buttons'>
                <button className={classes.button}>
                    <Link to="/search" className={classes.link}>Search Page</Link>
                </button>
            </div>
            <div>
                <button className={classes.button}>
                    <Link to="/wishlist" className={classes.link}>Wishlist Page</Link>
                </button>
            </div>
        </header>




    );
};

export default Header;

