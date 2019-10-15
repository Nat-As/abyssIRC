#include <sys/wait.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(void)
{
    pid_t pids[10];
    int i;

    for (i = 9; i >= 0; --i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            system("echo Hello world");
            sleep(i+10);
            _exit(0);
        }
    }

    for (i = 9; i >= 0; --i)
        waitpid(pids[i], NULL, 0);

    return 0;
}