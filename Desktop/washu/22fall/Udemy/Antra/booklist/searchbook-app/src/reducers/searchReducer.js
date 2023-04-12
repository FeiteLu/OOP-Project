import { SEARCH_BOOKS_REQUEST, SEARCH_BOOKS_SUCCESS, SEARCH_BOOKS_FAILURE } from '../actions/searchActions';

const initialState = {
    isLoading: false,
    error: null,
    results: [],
};

const searchReducer = (state = initialState, action) => {
    switch (action.type) {
        case SEARCH_BOOKS_REQUEST:
            return {
                ...state,
                isLoading: true,
                error: null,
                results: [],
            };
        case SEARCH_BOOKS_SUCCESS:
            return {
                ...state,
                isLoading: false,
                error: null,
                results: action.payload,
            };
        case SEARCH_BOOKS_FAILURE:
            return {
                ...state,
                isLoading: false,
                error: action.payload,
                results: [],
            };
        default:
            return state;
    }
};

export default searchReducer;
