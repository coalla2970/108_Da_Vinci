FLAGS = -pedantic-errors -std=c++11

tools.o: tools.cpp tools.h card.h
	g++ $(FLAGS) -c $<

welcomemsg.o: welcomemsg.cpp welcomemsg.h tools.h card.h
	g++ $(FLAGS) -c $<

checkpassword.o: checkpassword.cpp checkpassword.h card.h
	g++ $(FLAGS) -c $<

primarysort.o: primarysort.cpp primarysort.h card.h
	g++ $(FLAGS) -c $<

showmycards.o: showmycards.cpp showmycards.h card.h
	g++ $(FLAGS) -c $<

showcardsback.o: showcardsback.cpp showcardsback.h tools.h card.h
	g++ $(FLAGS) -c $<

subsort.o: subsort.cpp subsort.h showmycards.h card.h
	g++ $(FLAGS) -c $<

naturalsort.o: naturalsort.cpp naturalsort.h card.h
	g++ $(FLAGS) -c $<

moving.o: moving.cpp moving.h showmycards.h tools.h card.h
	g++ $(FLAGS) -c $<

sorting.o: sorting.cpp sorting.h subsort.h naturalsort.h moving.h card.h
	g++ $(FLAGS) -c $<

newcardinfo.o: newcardinfo.cpp newcardinfo.h card.h
	g++ $(FLAGS) -c $<

cardindeck.o: cardindeck.cpp cardindeck.h tools.h card.h
	g++ $(FLAGS) -c $<

primarydeal.o: primarydeal.cpp primarydeal.h cardindeck.h tools.h card.h
	g++ $(FLAGS) -c $<

deal.o: deal.cpp deal.h cardindeck.h card.h
	g++ $(FLAGS) -c $<

didplayerlose.o: didplayerlose.cpp didplayerlose.h card.h
	g++ $(FLAGS) -c $<

guessing.o: guessing.cpp guessing.h showcardsback.h didplayerlose.h tools.h checkpassword.h card.h
	g++ $(FLAGS) -c $<

emptydeck.o: emptydeck.cpp emptydeck.h card.h
	g++ $(FLAGS) -c $<

recall_data.o: recall_data.cpp recall_data.h card.h
	g++ $(FLAGS) -c $<

save_data.o: save_data.cpp save_data.h card.h
	g++ $(FLAGS) -c $<

countshown.o: countshown.cpp countshown.h card.h
	g++ $(FLAGS) -c $<

DAVINCI.o: DAVINCI.cpp welcomemsg.h tools.h checkpassword.h primarysort.h showmycards.h showcardsback.h cardindeck.h countshown.h didplayerlose.h deal.h emptydeck.h guessing.h moving.h naturalsort.h newcardinfo.h primarydeal.h recall_data.h save_data.h sorting.h subsort.h card.h
	g++ $(FLAGS) -c $<

DAVINCI: DAVINCI.o countshown.o save_data.o recall_data.o emptydeck.o guessing.o didplayerlose.o deal.o primarydeal.o cardindeck.o newcardinfo.o sorting.o moving.o naturalsort.o subsort.o showcardsback.o showmycards.o primarysort.o checkpassword.o welcomemsg.o tools.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o DAVINCI

.PHONY: clean
