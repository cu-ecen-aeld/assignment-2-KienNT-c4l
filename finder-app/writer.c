#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Mở syslog với facility LOG_USER
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid arguments. Usage: %s <writefile> <writestr>", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr  = argv[2];

    // Dùng system call open()
    int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        syslog(LOG_ERR, "Could not open file %s: %s", writefile, strerror(errno));
        closelog();
        return 1;
    }

    // Dùng system call write()
    ssize_t n = write(fd, writestr, strlen(writestr));
    if (n == -1) {
        syslog(LOG_ERR, "Failed to write to file %s: %s", writefile, strerror(errno));
        close(fd);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Đóng file với system call close()
    close(fd);
    closelog();
    return 0;
}
