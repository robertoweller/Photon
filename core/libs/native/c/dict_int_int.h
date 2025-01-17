typedef struct dict_int_int {
    list_int keys;
    list_int values;
} dict_int_int;

int dict_int_int_get(dict_int_int* self, int key) {
    int k;
    for (int n=0; n<self->keys.len; n++) {
        k = list_int_get(&self->keys,n);
        if (key == k) {
            return list_int_get(&self->values,n);
        }
    }
    printf("KeyError: The key %ld was not found.\n", key);
    exit(-1);
}
void dict_int_int_set(dict_int_int* self, int key,int value) {
    for (int n=1; n<self->keys.len; n++) {
        if (key == list_int_get(&self->keys, n)) {
            list_int_set(&self->values, n, value);
            return;
        }
    }
    list_int_append(&self->keys,key);
    list_int_append(&self->values,value);
}
