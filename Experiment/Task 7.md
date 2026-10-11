Repositori ini berisi contoh implementasi struktur data **Doubly Linked List (DLL)** dalam bahasa C++. Konsep ini didemonstrasikan menggunakan studi kasus navigasi level pada game **Geometry Dash**.

Berikut adalah kode utama yang mensimulasikan pembuatan, navigasi, penambahan, dan penghapusan level menggunakan Doubly Linked List:

```cpp
#include "list.h"
#include <iostream>

using namespace std;

int main() {
    Node* node1 = new Node{"Stereo Madness (1)", nullptr, nullptr};
    Node* node2 = new Node{"Base After Base (2)", nullptr, nullptr};
    Node* node3 = new Node{"Nine Circles (3)", nullptr, nullptr};
    Node* node4 = new Node{"Leyak (4)", nullptr, nullptr};
    Node* node5 = new Node{"Grief (5)", nullptr, nullptr};

    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node4;

    node4->prev = node3;
    node4->next = node5;

    node5->prev = node4;

    cout << "Original List: ";
    displayList(node1);

    cout << "\nForward:" << endl;
    forwardTraversal(node1);

    cout << "\nBackward:" << endl;
    backwardTraversal(node5);

    cout << "\nInsert Middle:" << endl;
    insertMiddle(node2, "Level X (Star)");
    
    cout << "\nForward:" << endl;
    forwardTraversal(node1);

    cout << "\nBackward:" << endl;
    backwardTraversal(node5);

    deleteNode(node3);

    cout << "\nAfter deleting Nine Circles (3) (Forward): \n";
    forwardTraversal(node1);

    cout << "\nAfter deleting Nine Circles (3) (Backward): \n";
    backwardTraversal(node5);

    return 0;
}
```


Doubly Linked List (DLL) sangat cocok untuk memodelkan urutan level game seperti Geometry Dash karena sangat menyerupai cara pemain menavigasi menu game dan cara playlist level khusus (custom levels) dikelola:

1. Navigasi Dua Arah (Bidirectional Navigation): Di Geometry Dash, pemain terus-menerus menggeser layar pemilihan level ke kiri dan kanan. Pointer `next` pada DLL memungkinkan pemain maju ke level berikutnya (misal: dari *Stereo Madness* ke *Base After Base*), sementara pointer `prev` memungkinkan mereka untuk langsung kembali. Fungsi traversal maju dan mundur dengan sempurna mensimulasikan usapan (swipe) pengguna di menu game.
2. Penyisipan di Tengah yang Mulus (Seamless Mid-List Insertion): Jika pemain sedang membuat playlist custom atau jika developer menambahkan level resmi baru, mereka mungkin ingin menyisipkannya di antara dua level yang sudah ada. Menambahkan "Level X" di antara dua level hanya memerlukan pembaruan beberapa pointer (pointer links). Jika menggunakan *Array*, menyisipkan level di tengah akan mengharuskan pergeseran semua level secara tidak efisien di dalam memori.
3. Penghapusan yang Efisien (Efficient Deletion): Jika pemain ingin menghapus level dari playlist yang disimpannya (misalnya menghapus *Nine Circles*), DLL memungkinkan penghapusan tersebut dengan kompleksitas waktu $O(1)$ (asalkan pointer ke node tersebut sudah diketahui). List akan secara otomatis "menyambung kembali" dengan menghubungkan level sebelum dan sesudahnya.
4. Ukuran Dinamis (Dynamic Size): Tidak seperti array standar yang membutuhkan ukuran tetap, DLL dapat bertambah dan berkurang secara dinamis. Pemain secara teoritis dapat mengantrekan level custom dalam jumlah tak terbatas di sebuah playlist tanpa mengharuskan program untuk mengalokasikan ulang blok memori besar.

Dengan menggunakan Doubly Linked List, pada dasarnya kita telah membangun logika dasar untuk sistem carousel pemilihan level yang dinamis dan dapat diedit.
