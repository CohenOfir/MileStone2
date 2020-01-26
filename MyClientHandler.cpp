#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include "Matrix.h"
#include "MatrixCreator.h"

MyClientHandler::MyClientHandler(Solver<Searchable<Point> *, string> *solver, CacheManager *cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyClientHandler::handleClient(int socketId) {
    cout << "Client connected" << endl;

    string prob;
    vector<string> partialProb;
    char buffer[256];
    string solution;
    char *chr;

    if (socketId < 0) {
        cout << "ERROR on accept" << endl;
        exit(1);
    }

    while (true) {
        bzero(buffer, 256);
        string line;
        int length = read(socketId, buffer, 256);
        length++;
        string buf = buffer;
        buf += "\n";
        if (length<0) {
            cout << "Socket error!" << endl;
            return;
        }
        for (int i = 0; i < length; i++) {
            char temp = buf[i];
            if (temp == '\n') {
                if (line.length() > 0) {
                    if (line == "end") {
                        cout << "Problem received from client, analyzing..." << endl;
                        MatrixCreator mc;
                        Searchable<Point> *matrix = mc.createMatrix(partialProb);
                        //get solution from file
                        if (this->cacheManager->isInCache(prob)) {
                            solution = this->cacheManager->getSolution(prob);
                            cout << "Problem exists in Cache, retrieving solution..." << endl;
                        } else {
                            cout << "Solving Problem..." << endl;
                            solution = solver->solve(matrix);
                            cacheManager->setSolution(prob, solution);
                            //cacheManager->saveToFile(prob, solution);
                        }

                        //write back to client
                        cout << "Sending Solution to client" << endl;
                        chr = const_cast<char *>(solution.c_str());
                        int isSent = write(socketId, chr, strlen(chr));

                        if (isSent == -1) {
                            cout << "ERROR sending Solution to client" << endl;
                            exit(1);
                        } else {
                            cout << "solution sent- " << solution << endl;
                        }
                        return;
                    }
                    partialProb.emplace_back(line);
                    prob += line;
                    line = "";

                }
            } else {
                line += temp;
            }
        }


    }
}




