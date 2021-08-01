/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>  /* �W�����o�� */
#include <stdlib.h> /* �W�����[�e�B���e�B */
#include <string.h> /* �����񏈗� */
#include <fcntl.h>  /* �t�@�C������ */
#include <io.h>     /* ���o�� */

/* main�֐��̒�` */
int main(void) {

    /* �ϐ��̐錾�E������ */
    char* buf = NULL;	/* char�^�o�b�t�@�|�C���^buf��NULL�ŏ�����. */
    char* content_type = NULL;	/* char�^�|�C���^content_type��NULL�ŏ�����. */
    char* p1 = NULL;	/* char�^�|�C���^p1��NULL�ŏ�����. */
    char* p2 = NULL;	/* char�^�|�C���^p2��NULL�ŏ�����. */
    char boundary[256] = { 0 };	/* char�^�o�b�t�@boundary(����256)��{0}�ŏ�����. */
    char* content_length = NULL;	/* char�^�|�C���^content_length��NULL�ŏ�����. */
    int len = 0;	/* content_length�𐮐��l�ɕϊ���������len��0�ŏ�����. */
    char pattern[256] = { 0 };	/* ��������boundary������pattern. */
    int read_len = 0;	/* �ǂݍ��߂�����read_len. */
    char* p3 = NULL;	/* char�^�|�C���^p3��NULL�ŏ�����. */
    char* p4 = NULL;	/* char�^�|�C���^p4��NULL�ŏ�����. */
    char* p5 = NULL;	/* char�^�|�C���^p5��NULL�ŏ�����. */
    int ret = 0;	/* memcmp�̖߂�lret��0�ŏ�����. */
    int i = 0;	/* ���[�v�p�ϐ�i��0�ŏ�����. */
    int rest = 0;	/* �R���e���c�擪����t�@�C���擪�܂ł̖��ʂȕ����̃T�C�Yrest��0�ŏ�����. */
    char file_content_type[256] = { 0 };	/* �t�@�C���R���e���g�^�C�v(����256)��{0}�ŏ�����. */
    char* file_buf = NULL;	/* char�^�o�b�t�@�|�C���^file_buf��NULL�ŏ�����. */
    
    /* CGI����. */
    content_type = getenv("CONTENT_TYPE");  /* getenv��content_type���擾. */
    p1 = strstr(content_type, "multipart/form-data");   /* "multipart/form-data"��T��. */
    if (p1 != NULL) {   /* ���������ꍇ. */
        p2 = strstr(p1, "boundary=");   /* "boundary="��T��. */
        if (p2 != NULL) {   /* ���������ꍇ. */
            strcpy(boundary, p2 + strlen("boundary=")); /* boundary�����o��. */
            content_length = getenv("CONTENT_LENGTH");  /* getenv��content_length���擾. */
            len = atoi(content_length); /* �����l�ɕϊ�. */
            buf = (char*)malloc(sizeof(char) * (len + 1));  /* malloc��buf���m��. */
            memset(buf, 0, len + 1);    /* memset��buf���N���A */
            setmode(fileno(stdin), O_BINARY);   // setmode��stdin���o�C�i�����[�h�ɃZ�b�g. */
            read_len = fread(buf, sizeof(char), len, stdin);    /* fread�œǂݍ���. */
            if (len == read_len) {  /* ��v */
                strcat(pattern, "--");  /* �܂�"--"���Z�b�g. */
                strcat(pattern, boundary);  /* boundary��A��. */
                p3 = strstr(buf, pattern);  /* buf����pattern��������. */
                if (p3 != NULL) {   /* ���������ꍇ. */
                    p4 = strstr(p3, "Content-Type: ");  /* "Content-Type"��T��. */
                    if (p4 != NULL) {   /* ���������ꍇ. */
                        p5 = strstr(p4, "\r\n\r\n");    /* "\r\n\r\n"��T��. */
                        if (p5 != NULL) {   /* ���������ꍇ. */
                            strncpy(file_content_type, p4 + strlen("Content-Type: "), p5 - (p4 + strlen("Content-Type: ")));    /* file_content_type�̒��o. */
                            rest = len - ((p5 + 4) - buf);  /* rest���v�Z. */
                            for (i = 0; i < rest; i++) {
                                ret = memcmp(p5 + 4 + i, pattern, strlen(pattern)); /* ��r. */
                                if (ret == 0) { /* ��v */
                                    file_buf = (char*)malloc(sizeof(char) * (i - 1));   /* malloc��file_buf���m��. */
                                    memset(file_buf, 0, i - 1); /* memset��file_buf���N���A */
                                    memcpy(file_buf, p5 + 4, i - 2);    /* file_buf�ɃR�s�[. */
                                    printf("Content-type: %s\n", file_content_type);    /* "Content-type: "��file_content_type���o��. */
                                    printf("Content-length: %d\n", i - 2);  /* "Content-length: "��i - 2���o��. */
                                    printf("\n");   /* printf�ŉ��s���o��. */
                                    setmode(fileno(stdout), O_BINARY);   // setmode��stdout���o�C�i�����[�h�ɃZ�b�g. */
                                    fwrite(file_buf, sizeof(char), i - 2, stdout);  /* �������� */
                                    free(file_buf); /* ��� */
                                    break;  /* ������. */
                                }
                            }
                        }
                    }
                }
            }
            free(buf);  /* buf�����. */
        }
    }

    /* �v���O�����̏I�� */
    return 0;   /* 0��Ԃ��Đ���I��. */

}