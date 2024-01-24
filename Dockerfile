FROM gcc:latest

WORKDIR usr/src/ex1

COPY ./src/ .

RUN g++ -o ex1 ./main.cpp FalsePositive.cpp BloomFilter.cpp AddURL.cpp ArgsHandler.cpp HashGenerator.cpp IsBlackListed.cpp ICommand.cpp URLsHandler.cpp  Flow.cpp


CMD ["./ex1"]


