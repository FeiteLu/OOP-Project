import { combineReducers } from 'redux';
import searchReducer from './searchReducer';
import wishlistReducer from './wishlistReducer';

const rootReducer = combineReducers({
    search: searchReducer,
    wishlist: wishlistReducer,
});

export default rootReducer;