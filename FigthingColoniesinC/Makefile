Hepsi: Derleme Calistirma

Derleme:
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/ExceptionHandling/Exception.c -o ./lib/Exception.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Taktik/Taktik.c -o ./lib/Taktik.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Taktik/TaktikDaire.c -o ./lib/TaktikDaire.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Taktik/TaktikHilal.c -o ./lib/TaktikHilal.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Uretim/Avcilik.c -o ./lib/Avcilik.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Uretim/Balikcilik.c -o ./lib/Balikcilik.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Uretim/Hayvancilik.c -o ./lib/Hayvancilik.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Uretim/Tarim.c -o ./lib/Tarim.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Uretim/Uretim.c -o ./lib/Uretim.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Koloni/Koloni.c -o ./lib/Koloni.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Oyun/Olustur.c -o ./lib/Olustur.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Oyun/Oyun.c -o ./lib/Oyun.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Oyun/OyunTuru.c -o ./lib/OyunTuru.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Oyun/Savaslar.c -o ./lib/Savaslar.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Utility/Dizi.c -o ./lib/Dizi.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Utility/Icerik.c -o ./lib/Icerik.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Utility/IcerikKontrol.c -o ./lib/IcerikKontrol.o
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) -c ./src/Utility/IcerikParcala.c -o ./lib/IcerikParcala.o

	
	gcc -I $(Include) -I $(Utility) -I $(HataKontrolu) -I $(Oyun) -I $(Koloni) -I $(Taktik) -I $(Uretim) ./lib/IcerikParcala.o ./lib/OyunTuru.o ./lib/Savaslar.o ./lib/IcerikKontrol.o ./lib/Icerik.o ./lib/Dizi.o ./lib/Oyun.o ./lib/Olustur.o ./lib/Koloni.o ./lib/Uretim.o ./lib/Tarim.o ./lib/Hayvancilik.o ./lib/Balikcilik.o ./lib/Avcilik.o ./lib/TaktikHilal.o ./lib/TaktikDaire.o ./lib/Taktik.o ./lib/Exception.o ./src/Test/Test.c -o ./bin/program.exe

Calistirma:
	./bin/program.exe

Include=./include/
HataKontrolu=./include/ExceptionHandling/
Koloni=./include/Koloni/
Taktik=./include/Koloni/Taktik/
Uretim=./include/Koloni/Uretim/
Oyun=./include/Oyun/
Utility=./include/Utility/


