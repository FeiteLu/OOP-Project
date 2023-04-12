export const ADD_TO_WISHLIST = 'ADD_TO_WISHLIST';
export const REMOVE_FROM_WISHLIST = 'REMOVE_FROM_WISHLIST';


export const addToWishlist = (book) => {
    return {
        type: ADD_TO_WISHLIST,
        payload: book,
    };
};

export const removeFromWishlist = (book) => {
    return {
        type: REMOVE_FROM_WISHLIST,
        payload: book.id,
    };
};
