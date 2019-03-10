#define XP_UNIX             //注意：这个不能丢！！
#include "jsapi.h"
#include "stdlib.h"
#include "string.h"


static void usage();
int main(void)
{
    JSRuntime *runtime = NULL;
    JSContext *context = NULL;
    JSObject *global = NULL;
    const char *script = "var a=1;var b=2;a+b";
    printf("script is \n%s\n", script);
    jsval rval;

    if (
            (!(runtime = JS_NewRuntime(1024L * 1024L)))
            || (!(context = JS_NewContext(runtime, 8192)))
            || (!(global = JS_NewObject(context, NULL, NULL, NULL)))
            )
        return EXIT_FAILURE;

    if (!JS_InitStandardClasses(context, global))
        return EXIT_FAILURE;

    if (!JS_EvaluateScript(context, global, script, strlen(script), "script", 1, &rval))
        return EXIT_FAILURE;

    printf("the script's result is \n%d\n",JSVAL_TO_INT(rval));

    JS_DestroyContext(context);
    JS_DestroyRuntime(runtime);
    JS_ShutDown();
    return EXIT_SUCCESS;
}
void usage()
{
    printf("example1 script_content\n");
    printf("for example:./example1 \"var a=1;b=2;a+b\"\n");
}
