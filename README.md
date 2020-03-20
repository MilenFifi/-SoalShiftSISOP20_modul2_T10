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
Source Code : [soal1.c](https://github.com/milenfifi/SoalShiftSISOP20_modul2_T10/blob/master/soal1/soal1.c) <br/>
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
Source Code : [soal2.c](https://github.com/milenfifi/SoalShiftSISOP20_modul2_T10/blob/master/soal2/soal2.c)<br/>
**Soal:**\
a.Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].<br/>
b. Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].<br/>
c. Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip).<br/>
d. Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men-generate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.<br/>
e. Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).<br/>

**Penjelasan Code:**\
dibaca dari main()<br/>
Deklarasi variabel
```
  pid_t child_id, child_id2, child_id3;     //deklarasi id

  time_t timer;                             //tipe data waktu 
  struct tm *info;                          //struktur yang berisi kalender, hari, dan waktu
  char tgl[80];                             //deklarasi variabel character tgl
  time( &timer );                           //deklarasi waktu 00:00:00 GMT menjadi waktu pada timer
  info = localtime( &timer );               //storing data info yaitu waktu timer menjadi waktu lokal
  strftime(tgl,80,"%Y-%m-%d_%X", info);     //storing data tgl dari data info yang dijadikan format "%Y-%m-%d_%X"
```
Forking Child dan masuk ke void a
```
child_id = fork();
  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }
  if (child_id == 0) {				//make directory
    a(tgl); }
```
void a
```
void a(char *tgl) {
  char *argv[3] = {"mkdir" , tgl , NULL};
  execv("/bin/mkdir", argv);
}
```
kembali ke main dan masuk ke void b
```
else {
    	child_id = wait(NULL);
    	child_id2 = fork();
    	if(child_id2 == 0){				//download and rename file
    	  b(tgl);}
```
void b
```
void b(char *tgl) {

  int status;                   //deklarasi variabel
  char url[100];
  time_t seconds, time2;        //tipe data waktu
  char tanggal2[100];

while ((wait(&status)) > 0);
        for (int i = 0; i < 20; i++)    //loop dengan syarat file tidak boleh lebih dari 20
        {
          if (fork() == 0)
          {
            chdir(tgl);                 //current working directory
            struct tm* info2;           //struktur yang berisi kalender, hari, dan waktu
        
            time2 = time(NULL);         //deklarasi 00:00:00 GMT
            info2 = localtime(&time2);  //storing info2 yaitu time2 yang menjadi waktu lokal
        
            int seconds = (int)time(NULL);      //store data seconds 00:00:00 GMT
            seconds = (seconds % 1000) + 100;   //Epoch Unix

            sprintf(url, "https://picsum.photos/%d", seconds);  //string print yang td seconds masih int

            char tanggal2[100];
            strftime(tanggal2, 100, "%Y-%m-%d_%H:%M:%S", info2);    //store tanggal2 menjadi format "%Y-%m-%d_%H:%M:%S" dari nilai info2
            char *argv[] = {"wget", url, "-qO", tanggal2, NULL};    //lakukan wget untuk url dengan -qO quiet output dengan nama tangga2
            execv("/usr/bin/wget", argv);       //execute wget
          }
          sleep(5); //lakukan tiap 5 detik
}}
```
kembali ke main dan masuk void c
```
else{							//zipping folder
      child_id2 = wait(NULL);
      child_id3 = fork();
      if(child_id3 == 0){
        c(tgl);
      }
```
void c
```
void c(char *tgl) {
  char yes[100];
  strcpy(yes, tgl);          //copy dari nama folder
  strcat(yes, ".zip");       //merge nama folder ditambah format.zip
  char *argv[5] = {"zip", "-r" , yes , tgl , NULL};     //zipping recursive directory
  execv("/bin/zip", argv);   //execute zip
}
```
kembali ke main dan melanjutkan nya yaitu prnghapusan folder awal setelah zipping
```
else{ child_id3 = wait(NULL);		//remove or delete directory	
          char *argv2[4] = {"rm", "-r" , tgl , NULL};
          execv("/bin/rm", argv2);
```

## 2. Multiprocessing
### soal3.c
Source Code : [soal2.c](https://github.com/milenfifi/SoalShiftSISOP20_modul2_T10/blob/master/soal3/soal3.c)<br/>
**Soal:**\
a. Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu
lima detik kemudian membuat direktori yang kedua bernama “sedaap”.<br/>
b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.<br/>
c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (didalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”. <br/>
d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).<br/>

**Penjelasan Code:**\
pembuatan folder indomie dan sedaap
```
int main() {

  pid_t child_id = fork();
  if (child_id == 0) {
    char *argv[] = {"mkdir", "-p", "/home/milenfifi/modul2/indomie", "/home/milenfifi/modul2/sedaap", NULL};
    execv("/bin/mkdir", argv);
  }
}
```

### Kendala yang dialami :
1. Bobot soal yang sangat sulit bagi kami untuk dikerjakan
2. Soal yang dibuat terlalu banyak cabangnya
3. Kami belum terbiasa dengan fungsi-fungsi program c yang bisa digunakan di ubuntu sehingga kami susah untuk mengerjakan semua soal dan membutuhkan waktu yang cukup lama untuk mengerjakannya sampai nomer 3 belum sempat tersentuh karena kebingungan di nomer 2
