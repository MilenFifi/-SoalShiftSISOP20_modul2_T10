# SoalShiftSISOP20_modul2_T10

## Jawaban Soal Shift Sistem Operasi 2020

## Modul 2

Oleh: 

* 05311840000020 Milenia Ulwan Zafira
* 05311840000042 I Komang Aditya Mahadiharja

## Daftar Isi
* [1. Crontab KW](#1-crontab-kw)
* [2. Kiwa Mantappu Jiwa](#2-kiwa-mantappu-jiwa)
* [3. Multiprocessing](#3-multiprocessing)

- - - 

## 1. Crontab KW
### soal1.c
Source Code : [soal1.c](https://github.com/milenfifi/SoalShiftSISOP20_modul2_T10/blob/master/soal1/soal1.c)
**Soal:**\
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:
1. Program menerima 4 argumen berupa:
    1. Detik: 0-59 atau * (any value)
    2. Menit: 0-59 atau * (any value)
    3. Jam: 0-23 atau * (any value)
    4. Path file .sh
2. Program akan mengeluarkan pesan error jika argumen yang  diberikan tidak sesuai
3. Program hanya menerima 1 config cron
4. Program berjalan di background (daemon)
5. Tidak boleh menggunakan fungsi system()

**Penjelasan Code:**\
buat loop agar argumen input tidak melebihi dari 4
```
 if (argc != 5) {
    printf("argumen salah\n");
```
deklarasi code
```
  int f1, f2, f3;
  time_t rawtime;   //tipe data waktu
  struct tm * tm;   //struktur yang berisi kalender, hari, dan waktu
```
deklarasi dalam loop
```
  while (1) {
  f1 = f2 = f3 = 0;         //deklarasi variabel awal = 0
  rawtime = time(0);        //deklarasi 00:00:00 GMT
  tm = localtime(&rawtime); //agar menjadi waktu yang ada pada komputer atau waktu lokal, bukan GMT
```
Penentuan variabel input
```
 if (tm->tm_sec == atoi(argv[1])) {     //array untuk input pertama yaitu seconds atau detik
      f1 = 1;
    }
    if (tm->tm_min == atoi(argv[2])) {   //array untuk input kedua yaitu minutes atau menit
      f2 = 1;
    }
    if (tm->tm_hour == atoi(argv[3])) {   //array untuk input ketiga yaitu hours atau jam
      f3 = 1;
    }
    if (f1 == 1 && f2 == 1 && f3 == 1) { //dan yang akan loop apabila dengan syarat semua input terisi
```
Execute bash
```
if (child_id == 0) {
        execv("/bin/bash", argf);
        sleep(1);
```

## 2. Kiwa Mantappu Jiwa
### soal2.c
Source Code : [soal2.c](https://github.com/milenfifi/SoalShiftSISOP20_modul2_T10/blob/master/soal2/soal2.c)

### Kendala yang dialami :
1. Bobot soal yang sangat sulit bagi kami untuk dikerjakan
2. Soal yang dibuat terlalu banyak cabangnya
3. Kami belum terbiasa dengan fungsi-fungsi program c yang bisa digunakan di ubuntu sehingga kami susah untuk mengerjakan semua soal dan membutuhkan waktu yang cukup lama untuk mengerjakannya
