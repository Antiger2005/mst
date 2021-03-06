// mst main
#include <mst.h>
#include <stdio.h> /* FILE, fopen, fprintf */

static inline float get_packing_percent(int num_verts, int num_edges) {
    int min_edges = num_verts - 1;
    int num_edges_scaled = num_edges - min_edges;
    int num_edge_choices = num_verts*(num_verts-1)/2 - min_edges;
    if(num_edge_choices == 0)
        return 1.0f;
    else
        return ((float)num_edges_scaled) / num_edge_choices;
}

int main(int argc, char **argv) {
#ifdef _DEBUG_
    if(argc != 2) {
        fprintf(stderr, "usage: ./mst <inputfile>\n");
        return 0;
    }
#endif

#if ALG == BEST_ALG
    FILE *input = fopen(argv[1], "r");
    unsigned num_verts, num_edges;
    fscanf(input, "%u", &num_verts);
    fscanf(input, "%u", &num_edges);
    fclose(input);

    float pom = get_packing_percent(num_verts, num_edges);
#ifdef _DEBUG_
    fprintf(stderr, "pom=%.f\n", pom);
#endif
    if(pom < 0.8f)
        kruskal_explicit_set_with_ps(argv[1]);
    else
        prim_dense(argv[1]);
#elif ALG == KRUSKAL_EXPLICIT_FS
    fprintf(stderr, "using kruskal explicit full-sort\n");
    kruskal_explicit_set_with_fs(argv[1]);
#elif ALG == KRUSKAL_EXPLICIT_PS
    fprintf(stderr, "using kruskal explicit partial-sort\n");
    kruskal_explicit_set_with_ps(argv[1]);
#elif ALG == KRUSKAL_IMPLICIT_FS
    fprintf(stderr, "using kruskal implicit full-sort\n");
    kruskal_implicit_set_with_fs(argv[1]);
#elif ALG == KRUSKAL_IMPLICIT_PS
    fprintf(stderr, "using kruskal implicit partial-sort\n");
    kruskal_implicit_set_with_ps(argv[1]);
#elif ALG == PRIM_DENSE
    fprintf(stderr, "using prim dense\n");
    prim_dense(argv[1]);
#elif ALG == PRIM_HEAP
    fprintf(stderr, "using prim heap\n");
    prim_heap(argv[1]);
#else
#   error Invalid ALG type
#endif
    return 0;
}
