import { ADD_TO_WISHLIST, REMOVE_FROM_WISHLIST } from '../actions/wishlistActions';

const initialState = {
    books: [],
};

const wishlistReducer = (state = initialState, action) => {
    switch (action.type) {
        case ADD_TO_WISHLIST:
            if (!state.books.includes(action.payload)) {
                return {
                    ...state,
                    books: [...state.books, action.payload],
                };
            }
        case REMOVE_FROM_WISHLIST:
            return {
                ...state,
                books: state.books.filter((book) => book.id !== action.payload),
            };
        default:
            return state;
    }
};

export default wishlistReducer;
