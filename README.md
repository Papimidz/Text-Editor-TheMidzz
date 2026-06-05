# Text Editor TheMidzz

## Deskripsi Singkat
Text Editor TheMidzz adalah aplikasi text editor berbasis console dengan bahasa C. Aplikasi ini memungkinkan pengguna membuat file baru, membuka file yang sudah ada, mengedit isi teks per baris, menyimpan perubahan, serta menghapus file dari sistem.

## Struktur Data Singkat
Project ini memakai struktur data linked list bertingkat:

- Setiap baris teks disimpan sebagai node pada doubly linked list.
- Isi satu baris disimpan lagi sebagai linked list karakter.
- Dengan cara ini, editor bisa mengelola teks secara dinamis tanpa ukuran tetap yang kaku.

## Pembagian File

### `main.c`
- Menampilkan menu utama program.
- Menangani pilihan pengguna seperti file baru, buka file, simpan file, hapus file, dan keluar.

### `hasbi.c` dan `hasbi.h`
- Mengatur struktur utama editor.
- Berisi fungsi untuk inisialisasi editor, menambah baris teks, menampilkan editor, dan mengambil isi teks ke buffer.

### `chyntia.c` dan `chyntia.h`
- Mengatur pengelolaan file.
- Berisi fungsi untuk membuat file kosong, membuka file, menyimpan file, dan menghapus file.

### `dzia.c` dan `dzia.h`
- Mengatur struktur teks per karakter.
- Berisi fungsi untuk inisialisasi text, menambah karakter, menampilkan teks, membersihkan memori, serta fitur find and replace.

## Fitur / Shortcut
Saat berada di dalam editor, pengguna dapat memakai perintah berikut:

- Teks biasa: ketik langsung untuk menambah baris baru.
- `/copy <baris>`: menyalin isi baris tertentu ke clipboard.
- `/cut <baris>`: memotong baris tertentu lalu menyimpannya ke clipboard.
- `/paste`: menempelkan isi clipboard ke akhir dokumen.
- `/replace`: mencari lalu mengganti kata atau kalimat pada isi dokumen.
- `/save`: menyimpan dokumen saat ini.
- `/close`: keluar dari mode editor dan kembali ke menu utama.

Menu utama program juga menyediakan:

- `New File`
- `Open File`
- `Save File`
- `Delete File`
- `Exit`

## Cara Compile
Gunakan perintah berikut untuk membuat file executable:

```bash
gcc main.c hasbi.c chyntia.c dzia.c -o editor
```

## Catatan
Project ini dibuat untuk pengolahan teks sederhana berbasis console dengan pendekatan linked list agar fleksibel dalam manajemen baris dan karakter.
