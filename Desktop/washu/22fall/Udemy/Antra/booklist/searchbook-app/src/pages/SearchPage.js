import React, { useState } from 'react';
import { connect } from 'react-redux';
import { Link } from 'react-router-dom';
import { searchBooks } from '../actions/searchActions';
import { addToWishlist } from '../actions/wishlistActions';
import "./searchPage.css";

const SearchPage = (props) => {
    const [query, setQuery] = useState('');

    const handleSubmit = (e) => {
        e.preventDefault();
        props.searchBooks(query);
    };

    const handleAddToWishlist = (book) => {
        props.addToWishlist(book);
    };


    return (
        <div>
            <form onSubmit={handleSubmit}>
                <input type="text" value={query} onChange={(e) => setQuery(e.target.value)} />
                <button type="submit">Search</button>
            </form>
            <ul key={JSON.stringify(props.results)}>
                {props.isLoading && <div>Loading...</div>}
                {props.error && <div>{props.error}</div>}
                {props.results.length > 0 &&
                    props.results.map((book) => (
                        <li key={book.id}>
                            <table>
                                <div >
                                    <Link to={`/book-detail/` + book.id}>
                                        {book.title}
                                    </Link>
                                </div>
                                <div>{book.author}</div>
                                <img src={book.thumbnail} alt={book.title} />
                                <button onClick={() => handleAddToWishlist(book)}>Add to Wishlist</button>
                            </table>
                        </li>
                    ))}
            </ul>
        </div>
    );
};

const mapStateToProps = (state) => ({
    isLoading: state.search.isLoading,
    error: state.search.error,
    results: state.search.results,
});

const mapDispatchToProps = (dispatch) => ({
    searchBooks: (query) => dispatch(searchBooks(query)),
    addToWishlist: (book) => dispatch(addToWishlist(book)),
});

export default connect(mapStateToProps, mapDispatchToProps)(SearchPage);
