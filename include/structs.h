typedef enum e_token_type {
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC
} t_token_type;

typedef struct s_token {
    t_token_type type;
    char *value;
    struct s_token *next;
	struct s_token *prev;
} t_token;