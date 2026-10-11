# Task 9: Eksperimen Bug — Lupa Update Pointer `next`/`prev`

## 🎯 Tujuan

Mendemonstrasikan apa yang terjadi ketika kita **lupa mengupdate pointer** `next` atau `prev` pada doubly linked list. Kita buat 2 bug yang disengaja, amati outputnya, lalu perbaiki.

---

## 🐛 Bug 1: `insertMiddle` — Lupa `prevNode->next = newNode`

### Kode Buggy

```cpp
void insertMiddle(Node* prevNode, string newData) {
    Node* newNode = new Node{newData, nullptr, nullptr};

    newNode->next = prevNode->next;   // ✅ newNode menunjuk ke node setelahnya
    newNode->prev = prevNode;         // ✅ newNode menunjuk ke prevNode

    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode; // ✅ node setelahnya menunjuk balik ke newNode
    }

    // ❌ BUG: lupa prevNode->next = newNode;
    // prevNode MASIH menunjuk ke node lama, bukan ke newNode!
}
```

### Apa yang Terjadi?

Insert "Song X" setelah "Song B":

```
Harusnya: A <-> B <-> X <-> C <-> D <-> E
```

**Forward traversal (dari A):**
```
Song A → Song B → Song C → Song D → Song E
```
❌ **Song X tidak muncul!** Karena `Song B->next` masih menunjuk ke `Song C`, bukan `Song X`.

**Backward traversal (dari E):**
```
Song E → Song D → Song C → Song X → Song B → Song A
```
✅ Song X muncul di backward! Karena `Song C->prev` sudah diupdate ke `Song X` (baris `prevNode->next->prev = newNode`).

### Visualisasi Bug

```
Forward direction (→) — RUSAK:
  A → B → C → D → E          (B masih skip ke C, X tidak terlewati)
                 
Backward direction (←) — BEDA HASIL:
  E → D → C → X → B → A     (C.prev sudah menunjuk ke X)

Song X "terputus" dari arah forward, tapi tersambung dari backward!
List TIDAK KONSISTEN — forward dan backward memberikan hasil berbeda.
```

---

## 🐛 Bug 2: `deleteNode` — Lupa `delNode->next->prev = delNode->prev`

### Kode Buggy

```cpp
void deleteNode(Node* delNode) {
    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next; // ✅ prev menunjuk ke next
    }

    if (delNode->next != nullptr) {
        // ❌ BUG: lupa delNode->next->prev = delNode->prev;
        // Node setelahnya MASIH menunjuk ke node yang sudah dihapus!
    }

    delete delNode;  // memory dibebaskan
}
```

### Apa yang Terjadi?

Delete "Song C" (setelah bug 1 di atas, state backward = `E→D→C→X→B→A`):

**Forward traversal (dari A):**
```
Song A → Song B → (blank) → Song D → Song E
```
✅ Forward hampir OK (B->next sudah diupdate lewat `prev->next = delNode->next`), tapi ada baris kosong karena Song X masih "menggantung".

**Backward traversal (dari E):**
```
Song E → Song D → (blank) → Song X → Song B → Song A
```
❌ **Backward RUSAK!** `Song D->prev` masih menunjuk ke `Song C` yang sudah di-`delete`! Ini mengakses **memory yang sudah dibebaskan** (dangling pointer) — bisa menyebabkan **crash, data sampah, atau undefined behavior**.

### Visualisasi Bug

```
Sebelum delete Song C:
  ... ← X ← C ← D ← ...
  
Setelah delete (tanpa update D->prev):
  ... ← X ← [DELETED/SAMPAH] ← D ← ...
                    ↑
            D->prev masih menunjuk ke sini!
            DANGLING POINTER! 💀
```

---

## ✅ Perbaikan

### Fix Bug 1: Tambahkan `prevNode->next = newNode`

```cpp
void insertMiddle(Node* prevNode, string newData) {
    Node* newNode = new Node{newData, nullptr, nullptr};

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;  // ✅ FIX: sambungkan prevNode ke newNode
}
```

### Fix Bug 2: Tambahkan `delNode->next->prev = delNode->prev`

```cpp
void deleteNode(Node* delNode) {
    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next;
    }

    if (delNode->next != nullptr) {
        delNode->next->prev = delNode->prev;
    }

    delete delNode;
}
```

---

## 📝 Kesimpulan

| Aspek | Bug 1 (lupa `prevNode->next`) | Bug 2 (lupa `next->prev`) |
|-------|-------------------------------|---------------------------|
| **Yang hilang** | Link forward ke node baru | Link backward melewati node dihapus |
| **Forward traversal** | ❌ Node baru tidak muncul | ✅ Terlihat OK |
| **Backward traversal** | ⚠️ Node muncul tapi urutan beda | ❌ Dangling pointer / crash |
| **Bahaya** | Data "hilang" dari satu arah | **Undefined behavior** — bisa crash! |
| **Pelajaran** | Doubly linked list HARUS update **kedua arah** | Setiap operasi harus menjaga **konsistensi** forward DAN backward |