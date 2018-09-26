#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct MemberNode {
	char studname[40];
	struct MemberNode *left;
	struct MemberNode *right;
}MemberNode;
typedef struct TreeNode {
	char clubname[40];
	struct TreeNode *left;
	struct TreeNode *right;
	MemberNode *member;
}TreeNode;
MemberNode *create_member(MemberNode *m, char stud[]) {
	MemberNode *current;
	if(m == NULL) {
		current = (MemberNode*)malloc(sizeof(MemberNode));
		assert(current != NULL);
		// printf("in create_member %s\n", stud );
		strcpy(current->studname, stud);
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	if(strcmp(stud, m->studname) < 0) m->left = create_member(m->left, stud);
	else if(strcmp(stud, m->studname) > 0) m->right = create_member(m->right, stud);
	return m;
}
TreeNode *create_club(TreeNode *root, char stud[], char club[]) {
	TreeNode *current;
	if(root == NULL) {
		current = (TreeNode*)malloc(sizeof(TreeNode));
		assert(current != NULL);
		// printf("%s %s\n",club, stud);
		strcpy(current->clubname, club);
		current->left = NULL;
		current->right = NULL;
		current->member = create_member(current->member, stud);
		return current;
	}
	if(strcmp(club, root->clubname) < 0) root->left = create_club(root->left, stud, club);
	else if(strcmp(club, root->clubname) > 0) root->right = create_club(root->right, stud, club);
	else if(strcmp(club, root->clubname) == 0) root->member = create_member(root->member, stud);
	return root;
}
TreeNode *find_club(TreeNode *root, char *club) {
	if(root == NULL){
		// printf("in NULL %s\n",root->clubname );
		return NULL;
	}
	if(strcmp(root->clubname, club) == 0) return root;
	if(strcmp(club, root->clubname) < 0) return find_club(root->left,club);
	if(strcmp(club, root->clubname) > 0) return find_club(root->right, club);
	else return root;
}
int find_member(MemberNode *member, char *stud) {
	if(member == NULL) return 0;
	if(strcmp(stud, member->studname) == 0) return 1;
	else if(strcmp(stud, member->studname) < 0) return find_member(member->left, stud);
	else if(strcmp(stud, member->studname) > 0) return find_member(member->right, stud);
	else return 0;
}
int main() {
	int K, ins, qr; scanf("%d", &K);
	TreeNode *root = NULL;

	char stud[40],club[40];
	for(int i = 0; i < K; i++) {
		scanf("%d %s %s", &ins, stud, club);
		root = create_club(root, stud, club);
		// printf("in for , root name is %s\n",root->clubname );
	}
	// printf("NOW the root is %s\n", root->clubname );
	int Q; scanf("%d", &Q);
	for(int i = 0; i < Q; i++) {
		scanf("%d", &qr);
		switch(qr) {
			case 0 :
				scanf("%s", club);
				TreeNode *now = find_club(root, club);
				if(now == NULL) puts("None");
				else {
					// printf("%s ", now->clubname );
					printf("%s\n", now->member->studname);
				}
				break;
			case 1 :
				scanf("%s %s", stud, club);
				now = find_club(root, club);
				if(now == NULL) puts("-1");
				else printf("%d\n",find_member(now->member, stud));
				break;
			default:
				break;
		}
	}
	return 0;
}