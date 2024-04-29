#include "../include/download.h"

int download(std::string downloadURL) {
    const char *url = downloadURL.c_str();
    ghttp_request *request = ghttp_request_new();
    ghttp_status status;

    if (ghttp_set_uri(request, (char*)url) == -1) {
        fprintf(stderr, "Error setting URI.\n");
        return -1;
    }

    if (ghttp_set_type(request, ghttp_type_get) == -1) {
        fprintf(stderr, "Error setting request type.\n");
        return -1;
    }

    if (ghttp_prepare(request) == -1) {
        fprintf(stderr, "Error preparing request.\n");
        return -1;
    }

    status = ghttp_process(request);
    if (status == ghttp_error) {
        fprintf(stderr, "Error processing request: %s\n", ghttp_get_error(request));
        return -1;
    }

    const char *body = ghttp_get_body(request);
    int body_len = ghttp_get_body_len(request);

    FILE *file = fopen("download.file", "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        return -1;
    }

    fwrite(body, body_len, 1, file);

    fclose(file);

    ghttp_request_destroy(request);

    return 0;
}
