# Makefile for the Caml Light compiler.

CAMLCOMP=../camlrun ../camlcomp -stdlib ../lib
CAMLLINK=../camlrun ../camllink -stdlib ../lib
CAMLLEX=../camlrun ../camllex
CAMLYACC=../camlyacc -s
CPP=/lib/cpp -P

COMPFLAGS=-O fast
LINKFLAGS=-g

OBJS=config.zo misc.zo const.zo prim.zo instruct.zo lambda.zo globals.zo \
 location.zo syntax.zo \
 errors.zo modules.zo builtins.zo types.zo \
 pr_type.zo ty_error.zo typing.zo ty_decl.zo pr_decl.zo ty_intf.zo \
 tr_env.zo match.zo trstream.zo front.zo back.zo \
 opcodes.zo prim_opc.zo buffcode.zo labels.zo reloc.zo \
 emitcode.zo emit_phr.zo \
 primdecl.zo lexer.zo par_aux.zo parser.zo compiler.zo \
 version.zo main.zo

all: camlcomp

camlcomp: $(OBJS)
	$(CAMLLINK) $(LINKFLAGS) -o camlcomp stdlib.zo $(OBJS)
        
clean:
	rm -f *.zi *.zo camlcomp
	rm -f opcodes.ml parser.ml parser.mli
	rm -f lexer.mll lexer.ml location.ml config.ml

install:
	cp camlcomp $(LIBDIR)/camlcomp

opcodes.ml: ../runtime/instruct.h
	sed -n -e '/^enum/p' -e 's/,//' -e '/^  /p' ../runtime/instruct.h | \
        awk -f ../tools/make-opcodes > opcodes.ml

lexer.mll: lexer.mlp
	$(CPP) -Dunix lexer.mlp > lexer.mll

lexer.ml: lexer.mll
	$(CAMLLEX) lexer.mll

parser.ml parser.mli: parser.mly
	$(CAMLYACC) parser.mly

.SUFFIXES :
.SUFFIXES : .mli .ml .zi .zo .mlp

.mli.zi:
	$(CAMLCOMP) $(COMPFLAGS) $<

.ml.zo:
	$(CAMLCOMP) $(COMPFLAGS) $<

.mlp.ml:
	@rm -f $@
	$(CPP) -Dunix $< > $@
	@chmod a-w $@

depend: lexer.ml parser.ml parser.mli opcodes.ml config.ml location.ml
	mv Makefile Makefile.bak
	(sed -n -e '1,/^### DO NOT DELETE THIS LINE/p' Makefile.bak; \
         ../tools/camldep *.mli *.ml) > Makefile
	rm Makefile.bak

location.ml: location.mlp
config.ml: config.mlp

### EVERYTHING THAT GOES BEYOND THIS COMMENT IS GENERATED
### DO NOT DELETE THIS LINE
lexer.zi: parser.zi 
parser.zi: syntax.zo 
pr_type.zi: globals.zo 
back.zo: prim.zo lambda.zo const.zo misc.zo instruct.zo 
buffcode.zo: misc.zo config.zi opcodes.zo 
builtins.zo: misc.zo modules.zo globals.zo const.zo 
compiler.zo: pr_decl.zo typing.zo parser.zi modules.zo location.zi const.zo \
    emit_phr.zo misc.zo back.zo front.zo ty_intf.zo syntax.zo instruct.zo \
    ty_decl.zo lexer.zi ty_error.zo globals.zo builtins.zo types.zo 
config.zo: config.zi 
const.zo: misc.zo 
emit_phr.zo: reloc.zo emitcode.zo buffcode.zo instruct.zo labels.zo 
emitcode.zo: prim.zo reloc.zo prim_opc.zo config.zi labels.zo const.zo \
    misc.zo instruct.zo buffcode.zo opcodes.zo 
errors.zo: misc.zo location.zi globals.zo const.zo 
front.zo: trstream.zo prim.zo lambda.zo tr_env.zo modules.zo location.zi \
    const.zo misc.zo match.zo syntax.zo ty_error.zo globals.zo builtins.zo 
globals.zo: prim.zo const.zo 
instruct.zo: prim.zo const.zo 
labels.zo: misc.zo buffcode.zo instruct.zo 
lambda.zo: prim.zo instruct.zo const.zo 
lexer.zo: lexer.zi misc.zo parser.zi 
location.zo: location.zi misc.zo config.zi 
main.zo: modules.zo config.zi compiler.zo misc.zo version.zo 
match.zo: prim.zo lambda.zo location.zi const.zo misc.zo syntax.zo \
    instruct.zo globals.zo 
misc.zo: config.zi 
modules.zo: misc.zo errors.zo globals.zo const.zo 
par_aux.zo: misc.zo errors.zo syntax.zo modules.zo location.zi builtins.zo \
    globals.zo const.zo 
parser.zo: parser.zi primdecl.zo par_aux.zo typing.zo syntax.zo builtins.zo \
    globals.zo types.zo const.zo 
pr_decl.zo: misc.zo pr_type.zi globals.zo const.zo 
pr_type.zo: pr_type.zi misc.zo modules.zo builtins.zo globals.zo types.zo \
    const.zo 
prim.zo: const.zo 
prim_opc.zo: misc.zo prim.zo opcodes.zo 
primdecl.zo: prim.zo globals.zo 
reloc.zo: buffcode.zo const.zo 
syntax.zo: location.zi globals.zo const.zo 
tr_env.zo: misc.zo prim.zo lambda.zo syntax.zo ty_error.zo globals.zo \
    const.zo 
trstream.zo: prim.zo lambda.zo tr_env.zo const.zo misc.zo match.zo \
    syntax.zo 
ty_decl.zo: misc.zo typing.zo syntax.zo modules.zo location.zi ty_error.zo \
    builtins.zo globals.zo types.zo const.zo 
ty_error.zo: misc.zo syntax.zo errors.zo pr_type.zi location.zi globals.zo \
    types.zo const.zo 
ty_intf.zo: misc.zo ty_decl.zo modules.zo ty_error.zo globals.zo types.zo \
    const.zo 
types.zo: misc.zo modules.zo builtins.zo globals.zo const.zo 
typing.zo: misc.zo errors.zo syntax.zo location.zi modules.zo ty_error.zo \
    builtins.zo globals.zo types.zo const.zo 