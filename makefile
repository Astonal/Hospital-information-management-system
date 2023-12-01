main: main.o ./src/global.o ./src/hospital.o ./src/address.o ./src/user.o ./src/person.o ./src/ambulance.o ./src/appointment.o ./src/doctor.o ./src/driver.o ./src/nurse.o ./src/patient.o ./include/global.hh ./include/hospital.hh ./include/address.hh ./include/user.hh ./include/person.hh ./include/ambulance.hh ./include/appointment.hh ./include/doctor.hh ./include/driver.hh ./include/nurse.hh ./include/patient.hh
	g++ main.o ./src/global.o ./src/hospital.o ./src/address.o ./src/user.o ./src/person.o ./src/ambulance.o ./src/appointment.o ./src/doctor.o ./src/driver.o ./src/nurse.o ./src/patient.o ./include/global.hh ./include/hospital.hh ./include/address.hh ./include/user.hh ./include/person.hh ./include/ambulance.hh ./include/appointment.hh ./include/doctor.hh ./include/driver.hh ./include/nurse.hh ./include/patient.hh -o main
main.o:main.cpp
	g++ -c main.cpp -o main.o
global.o: ./src/global.cpp
	g++ -c ./src/global.cpp -o ./src/global.o
hospital.o: ./src/hospital.cpp
	g++ -c ./src/hospital.cpp -o ./src/hospital.o
address.o:./src/address.cpp
	g++ -c ./src/address.cpp -o ./src/address.o
user.o:./src/user.cpp
	g++ -c ./src/user.cpp -o ./src/user.o
person.o:./src/person.cpp
	g++ -c ./src/person.cpp -o ./src/person.o
ambulance.o:./src/ambulance.cpp
	g++ -c ./src/ambulance.cpp -o ./src/ambulance.o
appointment.o:./src/appointment.cpp
	g++ -c ./src/appointment.cpp -o ./src/appointment.o
doctor.o: ./src/doctor.cpp
	g++ -c ./src/doctor.cpp -o ./src/doctor.o
driver.o:./src/driver.cpp
	g++ -c ./src/driver.cpp -o ./src/driver.o
nurse:./src/nurse.cpp
	g++ -c ./src/nurse.cpp -o ./src/nurse.o
patient:./src/patient.cpp
	g++ -c ./src/patient.cpp -o ./src/patient.o

clean:
	rm *.o 
	rm main
