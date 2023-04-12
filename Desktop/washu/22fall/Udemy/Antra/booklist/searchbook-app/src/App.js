import { Route, Routes } from 'react-router-dom';
import './App.css';
import Layout from './layout/Layout';
import SearchPage from './pages/SearchPage';
import WishlistPage from './pages/WishlistPage';
import BookDetailPage from './pages/BookDetailPage';

function App() {
  return (
    <Layout>
      <div className="App">
        <Routes>
          <Route path="/" element={<SearchPage />} exact></Route>
          <Route path="/search" element={<SearchPage />}></Route>
          <Route path="/wishlist" element={<WishlistPage />}></Route>
          <Route path="/book-detail/:bookId" element={<BookDetailPage />}></Route>
        </Routes>
      </div >

    </Layout >
  );
}

export default App;
