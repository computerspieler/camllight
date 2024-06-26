/* output.c */
void output(void);
void output_rule_data(void);
void output_yydefred(void);
void output_actions(void);
void token_actions(void);
void goto_actions(void);
int default_goto(int symbol);
void save_column(int symbol, int default_state);
void sort_actions(void);
void pack_table(void);
int matching_vector(int vector);
int pack_vector(int vector);
void output_base(void);
void output_table(void);
void output_check(void);
void output_transl(void);
void output_stored_text(void);
void output_debug(void);
void output_trailing_text(void);
void copy_file(FILE **file, char *file_name);
void output_semantic_actions(void);
void output_entries(void);
void free_itemsets(void);
void free_shifts(void);
void free_reductions(void);
