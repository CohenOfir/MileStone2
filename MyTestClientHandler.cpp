#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solve,
                                         CacheManager*cacheManager) {
    this->solver = solve;
    this->cm = cacheManager;
}

void MyTestClientHandler:: handleClient(int client_socket){
    while(true) {

        char message[1024] = {0};
        int valRead = read(client_socket, message, 1024);
        if(valRead == 0) {
            break;
        }
        string problem = string(message), solution;
        problem = problem.substr(0, problem.find('\r'));

        if (problem == "end") {
            cout << "end" << endl;
            close(client_socket);
            break;
        }

        cout << "problem : " << message << endl;

        if(cm->isInCache(problem)) {
            solution = cm->getSolution(problem);
        }else {
            solution = solver->solve(problem);
            cm->setSolution(problem, solution);
        }

        cout<<"solution : "<<solution<<endl;
        char *bufferOut = &solution[0];
        int is_send = send(client_socket, bufferOut, solution.length(), 0);
        if (is_send == -1) {
            cerr << "error sending massage to client" << endl;
        }
    }
}
