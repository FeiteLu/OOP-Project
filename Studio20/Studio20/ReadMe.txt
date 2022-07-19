Studio 20 ReadMe.txt

1) Klein Morrow, Feite Lu

2) Because if you don't call delete on the proxy, you might leak the real object that it points to.
Whenever you call delete on the pointer to the proxy, you also have to call delete on the object it points to
when items are allocated in the heap.

3) We tried testing where the password to access the write function was wrong and both read and accept were right.
This resulted in the output not being printed (expected). We then tried testing where write and accept were right
and the password typed in for read was wrong. This resulted in the output still being printed. When we tested for
the passwords of write and read being correct and the password for accept was wrong, the output was not printed.
