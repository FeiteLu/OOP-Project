import React, { useEffect, useState } from 'react';
import { useSelector } from 'react-redux';
import { useParams } from 'react-router-dom';
import "./bookDetailPage.css"


const BookDetailPage = () => {
    const { bookId } = useParams();
    const books = useSelector(state => state.search.results);
    const [book, setBook] = useState("");
    const isLoading = useSelector(state => state.search.isLoading);




    useEffect(() => {
        const filtered = books.filter((item) => item.id === bookId);
        setBook(filtered[0]);
    }, [bookId])

    return (
        <div>
            {isLoading && <div>Loading...</div>}
            {!isLoading && book && (
                <div>
                    <h2>{book?.title}</h2>
                    <div>Author: {book?.author}</div>
                    <div>Publisher: {book?.publisher}</div>
                    <div>Published Date: {book?.publishedDate}</div>
                    <div>Page Count: {book?.pageCount}</div>
                    <img src={book?.thumbnail} alt={book?.title} />
                    <p>{book?.description}</p>
                </div>
            )}
        </div>
    );
};

export default BookDetailPage;
