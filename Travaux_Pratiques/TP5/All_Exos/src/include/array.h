#ifndef _ARRAY_H_
#define _ARRAY_H_
    
    /* 
    * Allocate memory for an array which can contain `size`
    * integers. The returned C array has memory for an extra last
    * integer labelling the end of the array. 
    */
    int* allocate_integer_array(int size);

    /* Free an integer array */
    void free_integer_array(int* tab);

    /**
     * Calcul et retourne la taille d'un tableau
     * @param array[] le tableau
     * @return taille
    */
    int array_size(int* array);

    /**
     * Affiche les elements d'un tableau sur la sortie standard
    */
    void print_array(int* array);

    /**
     * Vérifie si deux tableaux ont le meme contenu
     * @param first[]
     * @param second[] 
     * @return 1 si ils ont le meme contenu, sinon
    */
    int are_arrays_equal(int* first, int* second);


    int* copy_array(int* array);


    int* fill_array();


    int* random_array(int size, int max_value);

    int* concatenate_arrays(int* first, int* second);
    int* merge_sorted_arrays(int* first, int* second);
    void split_arrays(int* array, int** first, int** second);
    int* merge_sort(int* array);

#endif /* _ARRAY_H_ */