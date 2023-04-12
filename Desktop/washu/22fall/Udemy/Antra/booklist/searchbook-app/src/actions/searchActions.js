import axios from 'axios';

export const SEARCH_BOOKS_REQUEST = 'SEARCH_BOOKS_REQUEST';
export const SEARCH_BOOKS_SUCCESS = 'SEARCH_BOOKS_SUCCESS';
export const SEARCH_BOOKS_FAILURE = 'SEARCH_BOOKS_FAILURE';

export const searchBooks = query => {
    return dispatch => {
        dispatch({ type: SEARCH_BOOKS_REQUEST });

        axios
            .get(`https://www.googleapis.com/books/v1/volumes?q=${query}&startIndex=0&maxResults=20`)
            .then(response => {
                const books = response.data.items.map(item => ({
                    id: item.id,
                    title: item.volumeInfo.title,
                    author: item.volumeInfo.authors ? item.volumeInfo.authors.join(', ') : 'Unknown Author',
                    publisher: item.volumeInfo.publisher,
                    publishedDate: item.volumeInfo.publishedDate,
                    pageCount: item.volumeInfo.pageCount,
                    description: item.volumeInfo.description,
                    thumbnail: item.volumeInfo.imageLinks ? item.volumeInfo.imageLinks.thumbnail : 'https://via.placeholder.com/128x192.png?text=No+Image',
                }));

                dispatch({
                    type: SEARCH_BOOKS_SUCCESS,
                    payload: books,
                });
            })
            .catch(error => {
                dispatch({
                    type: SEARCH_BOOKS_FAILURE,
                    payload: error.message,
                });
            });
    };
};


