/*
** $Id$
*/

#include "hypermail.h"
#include "defaults.h"
#include "setup.h"
#include "struct.h"
#include "setup.h"

char *set_language;
char *set_htmlsuffix;
char *set_mbox;
char *set_archives;
char *set_custom_archives;
char *set_about;
char *set_dir;
char *set_defaultindex;

bool set_overwrite;
bool set_inlinehtml;
bool set_increment;
bool set_readone;
bool set_reverse;
bool set_showprogress;
bool set_showheaders;
bool set_showhtml;
bool set_showbr;
bool set_showhr;
bool set_showreplies;
bool set_show_msg_links;
bool set_usetable;
bool set_indextable;
bool set_iquotes;
bool set_eurodate;
bool set_require_msgids;
bool set_discard_dup_msgids;
bool set_usemeta;
bool set_uselock;
bool set_ietf_mbox;
bool set_spamprotect;
#ifdef CHANGE_12DEC2000_BC
bool set_attachmentsindex;
#endif

int set_thrdlevels;
int set_dirmode;
int set_filemode;

int set_locktime;

char *set_mailcommand;
char *set_newmsg_command;
char *set_replymsg_command;
char *set_mailto;
char *set_hmail;
char *set_domainaddr;
char *set_htmlbody;

char *set_icss_url;
char *set_mcss_url;

char *set_label;

char *set_dateformat;
char *set_stripsubject;

struct hmlist *set_text_types = NULL;
struct hmlist *set_inline_types = NULL;
struct hmlist *set_prefered_types = NULL;
struct hmlist *set_ignore_types = NULL;
struct hmlist *set_show_headers = NULL;

char *set_ihtmlheader;
char *set_ihtmlfooter;
char *set_mhtmlheader;
char *set_mhtmlfooter;
char *set_attachmentlink;

struct Config cfg[] = {
    {"language", &set_language, LANGUAGE, CFG_STRING,
     "# A two-letter string specifying the language to use!\n"
     "# For example 'en' for English\n"},

    {"htmlsuffix", &set_htmlsuffix, HTMLSUFFIX, CFG_STRING,
     "# Use this to specify the html file suffix to be used\n"
     "# when Hypermail generates the html files. This is depen-\n"
     "# dent on local needs. Do not put a '.' in the value. It\n"
     "# would result in \"file..html\", probably not what you want.\n"},

    {"mbox", &set_mbox, NULL, CFG_STRING,
     "# This is the mailbox to read messages in from. Set this with \n"
     "# a value of NONE to read from standard input.\n"},

     {"ietf_mbox",  &set_ietf_mbox, BFALSE, CFG_SWITCH,
     "# Set this to On to read mboxes using the IETF convention.\n"},

    {"archives", &set_archives, NULL, CFG_STRING,
     "# This will create a link in the archived index pages\n"
     "# labeled 'Other mail archives' to the specified URL. Set\n"
     "# this to NONE to omit such a link.\n"},

    {"custom_archives", &set_custom_archives, NULL, CFG_STRING,
     "# If this variable is defined, a navigation entry will be\n"
     "# created below the sorted_by_x list entry, with the text\n"
     "# Other mail archives: followed by the value of this variable.\n"
     "# Set it to NONE to ommit such an entry.\n"},

    {"about", &set_about, NULL, CFG_STRING,
     "# This will create a link in the archived index pages\n"
     "# labeled 'About this archive' to the specified URL. Set\n"
     "# this to NONE to omit such a link.\n"},

    {"label", &set_label, NULL, CFG_STRING,
     "# Define this as the label to put in archives.\n"},

    {"dir", &set_dir, NULL, CFG_STRING,
     "# This is the directory that Hypermail will look for when\n"
     "# creating  and updating archives. If defined as NONE the\n"
     "# directory will have the same name as the input mailbox.\n"},

    {"defaultindex", &set_defaultindex, DEFAULTINDEX, CFG_STRING,
     "# This specifies the default index that  users can view when\n"
     "# entering the archive. Valid types are date, thread, author,\n"
     "# and subject.\n"},

    {"overwrite", &set_overwrite, BTRUE, CFG_SWITCH,
     "# Set this to On to make Hypermail overwrite existing archives.\n"},

    {"inlinehtml", &set_inlinehtml, BTRUE, CFG_SWITCH,
     "# Define to On to make text/html parts to get inlined with the mails.\n"
     "# If set to Off, HTML-parts will be stored as separate files.\n"},

    {"increment", &set_increment, BFALSE, CFG_SWITCH,
     "# Set this to On to append the input to existing archive.\n"},

    {"readone", &set_readone, BFALSE, CFG_SWITCH,
     "# Set this to On to specify there is only one message in the input.\n"},

    {"reverse", &set_reverse, BFALSE, CFG_SWITCH,
     "# Setting this variable to On will reverse-sort the article\n"
     "# entries in the date and thread index files by the\n"
     "# date they were received. That is, the most recent messages\n"
     "# will appear at the top of the index rather than the other\n"
     "# way around.\n"},

    {"progress", &set_showprogress, INT(PROGRESS), CFG_INTEGER,
     "# Set this to 1 or 2 to always show a progress report  as\n"
     "# Hypermail works. With a setting of 1, hypermail\n"
     "# overwrites the progress information relating to attachment\n"
     "# creation. With a setting of 2, attachment creation information\n"
     "# is listed individually with the number of the message the\n"
     "# attachments relate to. This is written to stdout.\n"},

    {"showheaders", &set_showheaders, BFALSE, CFG_SWITCH,
     "# Set this to On to show the article header lines in the archived HTML\n"
     "# files.  These lines typically include the To:, From:, and Subject:\n"
     "# information found in most email messages.\n"},

    {"showhtml", &set_showhtml, BTRUE, CFG_SWITCH,
     "# Set this to On to show the articles in a proportionally-spaced\n"
     "# font rather than a fixed-width (monospace) font.\n"},

    {"showbr", &set_showbr, BTRUE, CFG_SWITCH,
     "# Set this to On to place <br> tags at the end of article lines.\n"
     "# Otherwise, all non-quoted article lines will word wrap. This\n"
     "# only takes effect if hm_showhtml is enabled.\n"},

    {"showhr", &set_showhr, BTRUE, CFG_SWITCH,
     "# Set this to On to place horizontal rules before and after articles.\n"},

    {"showreplies", &set_showreplies, BTRUE, CFG_SWITCH,
     "# Set this to On to show all replies to a message as links\n"
     "# in article files.\n"},

    {"show_msg_links", &set_show_msg_links, BTRUE, CFG_SWITCH,
     "# Set this to On to put the individual message links at the top\n"
     "# of the individual message pages. Set this to Off to produce pages\n"
     "# without the Next, Previous, Reply, In-Reply-To, etc. links.\n"},

    {"usetable", &set_usetable, BFALSE, CFG_SWITCH,
     "# Setting this variable to On will tell Hypermail to generate\n"
     "# an index menu at the top and bottom of each page in a table\n"
     "# format. Set to Off if you want the standard Hypermail page look\n"
     "# and feel\n"},

    {"indextable", &set_indextable, BFALSE, CFG_SWITCH,
     "# Setting this variable to On will tell Hypermail to generate\n"
     "# message index Subject/Author/Date listings using a nice table\n"
     "# format. Set to Off if you want the original Hypermail index look.\n"},

    {"iquotes", &set_iquotes, BTRUE, CFG_SWITCH,
     "# Set this to On to italicize quoted lines.\n"},

    {"eurodate", &set_eurodate, BFALSE, CFG_SWITCH,
     "# Set this to On to display article received dates with\n"
     "# days before months instead of months before days.\n"},

    {"discard_dup_msgids", &set_discard_dup_msgids, BTRUE, CFG_SWITCH,
     "# Set this to Off to accept messages with a Message-ID matching\n"
     "# that of a message already  in this archive.\n"
     "# By default such messages are discarded.\n"},

    {"require_msgids", &set_require_msgids, BTRUE, CFG_SWITCH,
     "# Set this to Off to accept messages without a Message-ID header.\n"
     "# By default such messages are discarded.\n"},

    {"usemeta", &set_usemeta, BFALSE, CFG_SWITCH,
     "# Set this to On to store the content type of a MIME attachment in\n "
     "# a metadata file.\n"},

    {"uselock", &set_uselock, BTRUE, CFG_SWITCH,
     "# Set this to On to use hypermail's internal locking mechanism.\n"},

    {"thrdlevels", &set_thrdlevels, INT(4), CFG_INTEGER,
     "# This specifies the number of thread levels to outline\n"
     "# in the thread index.\n"},

    {"dirmode", &set_dirmode, INT(0755), CFG_OCTAL,
     "# This is an octal number  representing  the  permissions\n"
     "# that new directories are set to when they are created.\n"},

    {"filemode", &set_filemode, INT(0644), CFG_OCTAL,
     "# This is an octal number representing the file permissions\n"
     "# that new files are set to when they are created.\n"},

    {"mailcommand", &set_mailcommand, MAILCOMMAND, CFG_STRING,
     "# This specifies the mail command to use when converting\n"
     "# email addresses to links. The variables $TO, $SUBJECT,\n"
     "# and $ID can be used in constructing the command string.\n"},

    {"mailto", &set_mailto, NULL, CFG_STRING,
     "# The address of the contact point that is put in the HTML header\n"
     "# line <link rev=made href=\"mailto:MAILTO\">. Setting this to NONE\n"
     "# disables <link...> header generation.\n"},

    {"hmail", &set_hmail, NULL, CFG_STRING,
     "# Set this to the list's submission address.\n"},

    {"newmsg_command", &set_newmsg_command, "mailto:$TO", CFG_STRING,
     "# This specifies the mail command to use when converting the\n"
     "# set_hmail address to links in replies. The variables $TO, $SUBJECT,\n"
     "# and $ID can be used in constructing the command string.\n"},

    {"replymsg_command", &set_replymsg_command, "not set", CFG_STRING,
     "# This specifies the mail command to use when converting the\n"
     "# set_hmail address to links in replies. The variables $TO, $SUBJECT,\n"
     "# and $ID can be used in constructing the command string. The value\n"
     "# from mailcommand will be used if this option is not specified.\n"},

    {"domainaddr", &set_domainaddr, DOMAINADDR, CFG_STRING,
     "# Set this to the domainname you want added to a mail address\n"
     "# appearing in the RFC822 field which lack a hostname.\n"},

    {"body", &set_htmlbody, BODY, CFG_STRING,
     "# This is the <body> line to use when generating the HTML pages.\n"},

    {"icss_url", &set_icss_url, NULL, CFG_STRING,
     "# Specifies a URL to an external CSS stylesheet for the index pages.\n"
     "The CSS will be associated to the indexes thru an HTML LINK element.\n"
    },

    {"mcss_url", &set_mcss_url, NULL, CFG_STRING,
     "# Specifies a URL to an external CSS stylesheet for the message pages.\n"
     "The CSS will be associated to the indexes thru an HTML LINK element.\n"
    },

    {"text_types", &set_text_types, NULL, CFG_LIST,
     "# This is a list of MIME types that you want hypermail to treat\n"
     "# exactly as if they were text/plain.\n"},

    {"inline_types", &set_inline_types, INLINE_TYPES, CFG_LIST,
     "# This is the list of MIME types that you want <img> tags to as\n"
     "# opposed to simply <a href> to from the message.\n"},

    {"prefered_types", &set_prefered_types, NULL, CFG_LIST,
     "# When mails using multipart/mixed types are scanned, this list of\n"
     "# MIME types defines which part you want presented in the result.\n"},

    {"ignore_types", &set_ignore_types, NULL, CFG_LIST,
     "# This is the list of MIME attachment types that  you  do\n"
     "# not want to do anything with.\n"},

    {"show_headers", &set_show_headers, NULL, CFG_LIST,
     "# This is the list of headers to be displayed if 'showheaders'\n"
     "# is set to On). They can be listed comma or space separated\n"
     "# all on a single line.\n"},

    {"ihtmlheaderfile", &set_ihtmlheader, NULL, CFG_STRING,
     "# Define path as the path to a template  file  containing\n"
     "# valid  HTML  formatting  statements  that  you  wish to\n"
     "# included at the top of every index page.\n"},

    {"ihtmlfooterfile", &set_ihtmlfooter, NULL, CFG_STRING,
     "# Define path as the path to a template  file  containing\n"
     "# valid  HTML  formatting  statements  that  you  wish to\n"
     "# included at the bottom of every index  page.\n"},

    {"mhtmlheaderfile", &set_mhtmlheader, NULL, CFG_STRING,
     "# Define path as the path to a template  file  containing\n"
     "# valid  HTML  formatting statements that you wish to use\n"
     "# at the top of every message page.\n"},

    {"mhtmlfooterfile", &set_mhtmlfooter, NULL, CFG_STRING,
     "# Define path as the path to a template  file  containing\n"
     "# valid HTML formatting statements you wish to use at the\n"
     "# bottom of every message page.\n"},

    {"locktime", &set_locktime, INT(3600), CFG_INTEGER,
     "# Specify number of seconds to wait for a lock before we\n"
     "# override it! .\n"},

    {"dateformat", &set_dateformat, NULL, CFG_STRING,
     "# Format (see strftime(3)) for displaying dates.\n"},

    {"stripsubject", &set_stripsubject, NULL, CFG_STRING,
     "# A word to be stripped from all subject lines.  Helps unclutter\n"
     "# mailing lists which add tags to subject lines.\n"},

    {"attachmentlink", &set_attachmentlink, NULL, CFG_STRING,
     "# Format of the attachment links.\n"
     "# %p for the full path to the attachment\n"
     "# %f for the file name part only\n"
     "# %d for the directory name only\n"
     "# %n for the message number\n" "# %c for the content type string\n"},

    {"spamprotect", &set_spamprotect, BFALSE, CFG_SWITCH,
     "# Set this to On to make hypermail not output real email addresses\n"
     "# in the output HTML but instead it will obfuscate them a little.\n"}

#ifdef CHANGE_12DEC2000_BC
    , {"attachmentsindex", &set_attachmentsindex, BTRUE, CFG_SWITCH,
     "# Set this to  Off to make hypermail not output an index of\n"
     "# messages with attachments.\n"}
#endif


};

/* ---------------------------------------------------------------- */

void MakeConfig(bool comments)
{
    int i;
    time_t now = time(NULL);
    if (comments) {
	fprintf(stdout,
		"#################################################################\n"
		"# This is an automatically generated config file done by\n"
		"# Hypermail " VERSION " patchlevel " PATCHLEVEL " - %s",
		ctime(&now));
    }
    for (i = 0; i < sizeof(cfg) / sizeof(cfg[0]); i++) {
	if (cfg[i].verbose) {
	    if (comments) {
		fputs("\n", stdout);
		fputs(cfg[i].verbose, stdout);
	    }
	    switch (cfg[i].flags) {
	    case CFG_STRING:
		if (cfg[i].changed && *(char **)cfg[i].value)
		    /* they differ, show the actual contents */
		    fprintf(stdout, "%s = %s\n", cfg[i].label,
			    *(char **)cfg[i].value);
		else if (comments)
		    /* show the default value, but commented */
		    fprintf(stdout, "#%s = %s\n", cfg[i].label,
			    cfg[i].def ? (char *)cfg[i].def : "");
		break;
	    case CFG_LIST:
		if (cfg[i].changed) {
		    print_list(cfg[i].label,
			       *(struct hmlist **)cfg[i].value);
		}
		else if (comments) {
		    /* show the default value, but commented */
		    fprintf(stdout, "#%s = %s\n", cfg[i].label,
			    cfg[i].def ? (char *)cfg[i].def : "");
		}
		break;
	    case CFG_OCTAL:
		if (cfg[i].changed)
		    /* they differ, show the actual contents */
		    fprintf(stdout, "%s = %lo\n", cfg[i].label,
			    *(long *)(cfg[i].value));
		else if (comments)
		    /* show the default value, but commented */
		    fprintf(stdout, "#%s = %lo\n", cfg[i].label,
			    (long)cfg[i].def);
		break;
	    case CFG_INTEGER:
		if (cfg[i].changed)
		    /* they differ, show the actual contents */
		    fprintf(stdout, "%s = %ld\n", cfg[i].label,
			    *(long *)(cfg[i].value));
		else if (comments)
		    /* show the default value, but commented */
		    fprintf(stdout, "#%s = %ld\n", cfg[i].label,
			    (long)cfg[i].def);
		break;
	    case CFG_SWITCH:
		if (cfg[i].changed)
		    /* they differ, show the actual contents */
		    fprintf(stdout, "%s = %s\n",
			    cfg[i].label,
			    *(long *)(cfg[i].value) ? "On" : "Off");
		else if (comments)
		    fprintf(stdout, "#%s = %s\n", cfg[i].label,
			    cfg[i].def ? "On" : "Off");
		break;
	    default:
		break;
	    }			/* end of switch() */
	}			/* end of if() */
    }				/* end of for() */
}				/* end of function */

static bool inited = FALSE;

void PreConfig(void)
{
    int i;
    char name[128] = "HM_";
    char *labp;
    int ind;
    void *defval;

    for (i = 0; i < sizeof(cfg) / sizeof(cfg[0]); i++) {
	cfg[i].changed = FALSE;

	/* build environment variable to read from */
	for (ind = 3, labp = cfg[i].label; *labp; labp++) {
	    name[ind++] = toupper(*labp);
	}
	name[ind] = 0;

	/* we try to get a default value from an environment variable */
	defval = getenv(name);
	if (!defval)
	    /* get the built-in default instead */
	    defval = cfg[i].def;

	switch (cfg[i].flags) {
	case CFG_STRING:
	    if (defval)
		*(char **)cfg[i].value = strsav(defval);
	    else
		*(char **)cfg[i].value = NULL;
	    break;
	case CFG_SWITCH:
	case CFG_INTEGER:
	case CFG_OCTAL:
	    *(int *)cfg[i].value = (int)defval;
	    break;
	case CFG_LIST:
	    if (defval) {
                char *tpstr;
                tpstr = strsav(defval);
		*(struct hmlist **)cfg[i].value = NULL;
		*(struct hmlist **)cfg[i].value =
		    (void *)add_list(*(struct hmlist **)cfg[i].value, tpstr);
                free(tpstr);
            }
	    else
		*(struct hmlist **)cfg[i].value = NULL;
	    break;
	default:
	    break;
	}
    }
    inited = TRUE;
}

void PostConfig(void)
{
    /* Keep default behavior the same as it was when mailcommand applied
    * to the cases now covered by replymsg_command. */
    if (!strcmp(set_replymsg_command, "not set"))
	set_replymsg_command = set_mailcommand;
}

int ConfigAddItem(char *cfg_line)
{
    char keyword[256];
    char towhat[501];
    char *keywp;
    int i;
    char *line = cfg_line;
 
    /* 
    ** This is here to support earlier config file formats. 
    ** The "set " is nolonger needed but has been added 
    ** for backwards compatability.
    */

    if (!strncmp (line, "set ", 4))
        line += 4;

    if (2 <= sscanf(line, " %255[a-zA-Z0-9._] %*[=: ] %500[^\n]",
		    keyword, towhat)) {

	if ('\"' == towhat[0]) {
	    /* we have a quote as the first character, then we assume we have a
	       "string" to parse instead of just string. */
	    sscanf(line, " %255[a-zA-Z0-9._] %*[=: ] \"%500[^\"]",
		   keyword, towhat);
	}
	else {
	    /* no quotes, we eat all trailing white spaces */
	    i = strlen(towhat);
	    if (i--) {
		while ((i >= 0) && isspace(towhat[i]))
		    towhat[i--] = 0;
	    }
	}

	if (!strncasecmp(keyword, "hm_", 3))
	    /* if there is a hm_ prefix, skip it! */
	    keywp = keyword + 3;
	else
	    keywp = keyword;

	for (i = 0; i < sizeof(cfg) / sizeof(cfg[0]); i++) {

	    if (*keywp != *(cfg[i].label)) 	/* minor speedup */
                continue;

	    if (!strcasecmp(keywp, cfg[i].label)) {	/* match */

		switch (cfg[i].flags) {
		case CFG_STRING:
		    *(char **)cfg[i].value = strsav(towhat);
		    break;
		case CFG_SWITCH:
		    if (atoi(towhat) ||
			!strcasecmp("ON", towhat) ||
			!strcasecmp("YES", towhat))
			    *(int *)cfg[i].value = (int)TRUE;
		    else
			*(int *)cfg[i].value = (int)FALSE;
		    break;
		case CFG_INTEGER:
		    /* get an integer using any base */
		    *(int *)cfg[i].value = strtol(towhat, NULL, 0);
		    break;
		case CFG_OCTAL:
		    /* get an octal number */
		    *(int *)cfg[i].value = strtol(towhat, NULL, 8);
		    break;
		case CFG_LIST:

                    /* Is this the first time that it's been called
                     * for this list ? If so then there is a value
                     * being set for the list via a config file.
                     * In the case of lists we need to replace the
                     * current value with the new material completely.
                     */
                    if (cfg[i].changed == FALSE) { /* first time through ? */
                        if (cfg[i].value) {
                            if (*(struct hmlist **)cfg[i].value)
                                 free(*(struct hmlist **)cfg[i].value);
		            *(struct hmlist **)cfg[i].value = NULL;
                        }
                    }
		    *(struct hmlist **)cfg[i].value =
		       (void *)add_list(*(struct hmlist **)cfg[i].value,towhat);
		    break;
		default:
		    break;
		}
		cfg[i].changed = TRUE;
		return 0;
	    }
	}
    }
    return 1;
}

int ConfigInit(char *filename)
{
    FILE *f;
    char line[MAXLINE];

    PreConfig();

    if (filename && *filename) {
	f = fopen(filename, "r");
	if (f) {
	    while (fgets(line, MAXLINE, f)) {
		if ((line[0] != '#') && (line[0] != '\n')) {
	            /* need to error check the format */
		    ConfigAddItem(line);
                }
            }
	    fclose(f);
	}
	else
	    return FALSE;
    }

    PostConfig();

    return TRUE;
}

void ConfigCleanup(void)
{
    int i;
    for (i = 0; i < sizeof(cfg) / sizeof(cfg[0]); i++) {
	switch (cfg[i].flags) {
	case CFG_LIST:
	    if (cfg[i].value) {
		if (*(struct hmlist **)cfg[i].value)
		    free(*(struct hmlist **)cfg[i].value);
	    }
	    break;
	case CFG_STRING:
	    if (cfg[i].value) {
		if (*(char **)cfg[i].value)
		    free(*(char **)cfg[i].value);
	    }
	    break;
	default:
	    break;
	}
    }
}

#ifdef DEBUG

void dump_config(void)
{
    register char *cp;

    printf("\nConfiguration Values:\n");

    printf("set_language = %s\n",set_language ? set_language : "Not Used");
    printf("set_htmlsuffix = %s\n",set_htmlsuffix ? set_htmlsuffix : "Not Used");
    printf("set_mbox = %s\n",*set_mbox ? set_mbox : "Not Used");
    printf("set_archives = %s\n",set_archives ? set_archives : "Not set");
    printf("set_custom_archives = %s\n",set_custom_archives ? set_custom_archives : "Not set");
    printf("set_about = %s\n",set_about ? set_about : "Not set");
    printf("set_dir = %s\n",set_dir ? set_dir : "Not set");
    printf("set_defaultindex = %s\n",set_defaultindex ? set_defaultindex : "Not set");
    
    printf("set_label = %s\n",set_label ? set_label : "Not set");
    printf("set_dateformat = %s\n",set_dateformat ? set_dateformat : "Not set");
    printf("set_stripsubject = %s\n",set_stripsubject ? set_stripsubject : "Not set");
    printf("set_mailcommand = %s\n",set_mailcommand ? set_mailcommand : "Not set");
    printf("set_bodymailcommand = %s\n",set_bodymailcommand ? set_bodymailcommand : "Not set");
    printf("set_mailto = %s\n",set_mailto ? set_mailto : "Not set");
    printf("set_hmail = %s\n",set_hmail ? set_hmail : "Not set");
    printf("set_domainaddr = %s\n",set_domainaddr ? set_domainaddr : "Not set");
    printf("set_htmlbody = %s\n",set_htmlbody ? set_htmlbody : "Not set");
    printf("set_icss_url = %s\n",set_icss_url ? set_icss_url : "Not set");
    printf("set_mcss_url = %s\n",set_mcss_url ? set_mcss_url : "Not set");

    /* Boolean or interger */

    printf("set_overwrite = %d\n",set_overwrite);
    printf("set_inlinehtml = %d\n",set_inlinehtml);
    printf("set_increment = %d\n",set_increment);
    printf("set_readone = %d\n",set_readone);
    printf("set_reverse = %d\n",set_reverse);
    printf("set_showprogress = %d\n",set_showprogress);
    printf("set_showheaders = %d\n",set_showheaders);
    printf("set_showhtml = %d\n",set_showhtml);
    printf("set_showbr = %d\n",set_showbr);
    printf("set_showhr = %d\n",set_showhr);
    printf("set_showreplies = %d\n",set_showreplies);
    printf("set_show_msg_links = %d\n",set_show_msg_links);
    printf("set_usetable = %d\n",set_usetable);
    printf("set_indextable = %d\n",set_indextable);
    printf("set_iquotes = %d\n",set_iquotes);
    printf("set_eurodate = %d\n",set_eurodate);
    printf("set_require_msgids = %d\n",set_require_msgids);
    printf("set_discard_dup_msgids = %d\n",set_discard_dup_msgids);
    printf("set_usemeta = %d\n",set_usemeta);
    printf("set_uselock = %d\n",set_uselock);
    printf("set_ietf_mbox = %d\n",set_ietf_mbox);
    printf("set_thrdlevels = %d\n",set_thrdlevels);
    printf("set_dirmode = %04o\n",set_dirmode);
    printf("set_filemode = %04o\n",set_filemode);
#ifdef CHANGE_12DEC2000_BC
    printf("set_spamprotect = %04o\n",set_spamprotect);
    printf("set_attachmentsindex = %04o\n",set_attachmentsindex);
#endif

    if (!set_ihtmlheader)
        printf("set_ihtmlheader = Not set\n");
    else {
        printf("set_ihtmlheader = ");
        for (cp = set_ihtmlheader; *cp; cp++)
             putchar(*cp);
    }

    if (!set_ihtmlfooter)
        printf("set_ihtmlfooter = Not set\n");
    else {
        printf("set_ihtmlfooter = ");
        for (cp = set_ihtmlfooter; *cp; cp++)
             putchar(*cp);
    }

    if (!set_mhtmlheader)
        printf("set_mhtmlheader = Not set\n");
    else {
        printf("set_mhtmlheader = ");
        for (cp = set_mhtmlheader; *cp; cp++)
             putchar(*cp);
    }

    if (!set_mhtmlfooter)
        printf("set_mhtmlfooter = Not set\n");
    else {
        printf("set_mhtmlfooter = ");
        for (cp = set_mhtmlfooter; *cp; cp++)
             putchar(*cp);
    }

    /* List values */

    print_list("set_text_types", set_text_types);
    print_list("set_inline_types", set_inline_types);
    print_list("set_prefered_types",set_prefered_types);
    print_list("set_ignore_types",set_ignore_types);
    print_list("set_show_headers", set_show_headers);

}

#endif
