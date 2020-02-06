// main.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mod1/mod1.h"
#include "xmlmemory.h"
#include "parser.h"
#include "cmakeconfig.h"


const char *curDoc = "<?xml version=\"1.0\"?>"
                     "<story>"
                     "<storyinfo>"
                     "<author>John Fleck</author>"
                     "<datewritten>June 2, 2002</datewritten>"
                     "<keyword>example keyword</keyword>"
                     "</storyinfo>"
                     "<body>"
                     "<headline>This is the headline</headline>"
                     "<para>This is the body text.</para>"
                     "</body>"
                     "</story>";

int main( int argc, char *argv[] )
{
    //Library test
    mod1_process();

    //Libxml2 test
    xmlDocPtr doc;
    xmlNodePtr cur;
    //doc = xmlParseFile(docname);
    doc = xmlParseDoc((const xmlChar *)curDoc);
    if (doc == NULL) {
        fprintf(stderr, "Document not parsed successfully. \n");
        return -1;
    }

    printf("parse document success!\n");

    cur = xmlDocGetRootElement(doc);
    if (cur == NULL) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return -1;
    }

    if (xmlStrcmp(cur->name, (const xmlChar *) "story")) {
        fprintf(stderr, "document of the wrong type, root node != story");
        xmlFreeDoc(doc);
        return -1;
    }

    printf("root elment value is %s\n", cur->name);

    xmlFreeDoc(doc);

    //cmakeconfig.h

    printf("flag = %d\n", USE_MY_LIB);

    #ifdef USE_MY_LIB
        printf("use my library\n");
    #endif

    #ifndef NDEBUG
       printf("author: %s, release_date: %s\n", AUTHOR, RELEASE_DATE); //只在开发版本编译
    #endif

    return 0;
}
