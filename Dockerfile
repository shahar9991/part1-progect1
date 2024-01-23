FROM gcc:latest

WORKDIR usr/src/part1-progect1/src/version2

COPY ./src/ .

RUN g++ -o part1-progect1 ./ArgssHandler1.cpp ./FalsePositive.cpp ./HashGenerator2.cpp  ./Bloom_Filter2.cpp ./URLsHandler1.cpp ./main_version2.cpp


