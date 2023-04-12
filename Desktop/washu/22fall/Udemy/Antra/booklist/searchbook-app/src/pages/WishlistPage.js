import React from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { removeFromWishlist } from '../actions/wishlistActions';
import "./wishlistPage.css"
import { Link } from 'react-router-dom';

const WishlistPage = () => {
    const dispatch = useDispatch();
    const wishlist = useSelector(state => state.wishlist.books);

    const handleRemoveFromWishlist = (book) => {
        dispatch(removeFromWishlist(book));
    }

    return (
        <div>
            <h2>Wishlist</h2>
            {wishlist.length === 0 && <div>Your wishlist is empty.</div>}
            {wishlist.length > 0 && (
                <ul>
                    {wishlist.map(book => (
                        <li key={book.id}>
                            <table>
                                <div >
                                    <Link to={`/book-detail/` + book.id}>
                                        {book.title}
                                    </Link>
                                </div>
                                <div>{book.author}</div>
                                <img src={book.thumbnail} alt={book.title} />
                                <button onClick={() => handleRemoveFromWishlist(book)}>Remove from Wishlist</button>
                            </table>
                        </li>
                    ))}
                </ul>
            )}
        </div>
    )
}

export default WishlistPage;
