```

To rest from his stressful last adventure, Doctor Who decides to attend a music recital performed by Her Majesty the Queen’s Royal Orchestra. Since he doesn’t want to be seen in public, the Doctor uses the TARDIS to channel the music directly from the Opera to his home.

But behold! The infamous Graske has detected an opportunity to do evil: the sound waves channelled by the TARDIS have created a space-time crack that the alien is using to travel through dimensions. He should soon reach Earth and annihilate the human race. Nothing less could have been expected from this vile creature!

The Doctor soon realizes that the only way to prevent this terrible fate is to make the TARDIS play the melodies backwards. This will reverse the polarity of the neutron flow and banish the Graske to the other side of the universe.

Unfortunately the melodies are only available on musical scores on paper and the TARDIS is not (yet) equipped with a score reader.

Your mission is to help Doctor Who defeat the Graske. To do so, you have to implement an interface that can read scanned musical scores directly from paper and translate them into musical notes.


The musical scores are fairly simple and only feature half notes () and quarter notes (). Notes are all represented on a staff and are limited to the following musical notes (either half or quarter):


Notes are labelled using the English convention: A B C D E F and G

As a reminder (for those not familiar with reading music):
On a score, a "staff" always contains 5 lines. Notes are either located accross a line or between two lines.
The first C note is located on a specific segment - a ledger line - below the 5 other lines.
The notes have tails which can either go up - until the first A - or down - from the second C. The tail of the B can go either way.
The label of a note (A, B, C, etc.) is independant of whether the note is a half or quarter note.
You are provided with scanned images of the scores in black and white encoded in a simple, yet efficient, form of RLE (Run-Length Encoding): the DWE (Doctor Who Encoding) algorithm.
In the DWE, consecutive pixels of the same color are encoded using a letter (B for black pixels, W for white pixels) followed by a space followed by the number of pixels of that color.

For example: W 5 B 20 W 16 means 5 white pixels, followed by 20 black pixels, followed by 16 white pixels.

Encoding is done from top to bottom. When the image width is known, reconstructing the original image is straightforward.

Within the images, the scores and notes have various sizes. To fully understand the challenge at hand, you should check all the images from this    page  . They correspond to the challenge tests further down.

All the test cases are contained within these 12 images and if your code can process them all, then you are good to go!
INPUT:
Line 1: the width W and height H of the image in pixels.
Line 2: the image encoded from top to bottom using the DWE algorithm: several couples of "C L" separated by spaces. C is the color of the pixels (either B for black or W for white), L is the number of contiguous pixels of the same color (may encompass multiple image lines).

OUTPUT:
Notes read from left to right separated by space characters.
Each note is composed of two characters. First the note itself: A B C D E F or G. Then its type: H for a half note or Q for a quarter note. There is no distinction between the first C and the second C (same goes for D, E, F, G).

CONSTRAINTS:
100 < W < 5000
70 < H < 300
Lines and tails have a width of at least 1 pixel.
Notes are separated by at least 1 pixel.
The space between two lines is at least 8 pixels wide and at least 4 times the width of a line.

EXAMPLE:
Input
120 176
W 4090 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 1020 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 26 B 10 W 82 B 2 W 25 B 12 W 81 B 2 W 23 B 4 W 8 B 4 W 79 B 2 W 23 B 2 W 12 B 2 W 79 B 2 W 22 B 2 W 14 B 2 W 78 B 2 W 21 B 3 W 14 B 3 W 77 B 2 W 21 B 2 W 16 B 2 W 77 B 2 W 20 B 3 W 16 B 3 W 36 B 64 W 18 B 18 W 20 B 64 W 18 B 18 W 20 B 64 W 18 B 18 W 20 B 64 W 18 B 18 W 60 B 2 W 20 B 2 W 18 B 2 W 76 B 2 W 20 B 3 W 16 B 3 W 76 B 2 W 20 B 3 W 16 B 2 W 77 B 2 W 20 B 4 W 14 B 3 W 77 B 2 W 20 B 4 W 14 B 2 W 78 B 2 W 20 B 2 W 1 B 2 W 12 B 2 W 79 B 2 W 20 B 2 W 1 B 4 W 8 B 4 W 79 B 2 W 20 B 2 W 3 B 12 W 81 B 2 W 20 B 2 W 4 B 10 W 82 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 96 B 2 W 20 B 2 W 56 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 46 B 10 W 4 B 2 W 20 B 2 W 81 B 12 W 3 B 2 W 20 B 2 W 79 B 16 W 1 B 2 W 20 B 2 W 79 B 16 W 1 B 2 W 20 B 2 W 78 B 20 W 20 B 2 W 77 B 21 W 20 B 2 W 77 B 21 W 20 B 2 W 76 B 22 W 20 B 2 W 76 B 22 W 20 B 2 W 76 B 22 W 20 B 2 W 76 B 22 W 20 B 2 W 76 B 22 W 20 B 2 W 76 B 22 W 20 B 2 W 76 B 22 W 20 B 2 W 77 B 20 W 21 B 2 W 77 B 20 W 21 B 2 W 78 B 18 W 22 B 2 W 79 B 16 W 23 B 2 W 79 B 16 W 23 B 2 W 81 B 12 W 25 B 2 W 56 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 2420 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 5050
Output
AQ DH


```

# ideas

- first, are all stems 2 pixels wide? - no
- are all ledger lines x pixels high - no
- lets print the pixel art! - mostly done

- organize the pixels into a 2d grid - done

- find ledger lines with horizontal freq (black count on rows)
- find stems to get notes
- check half or quarter by checking squares to left of stem for black dots

- next step: freq counts
- next step - sortable freq counts
  - sorted, keeping info on original row/col - done

- next step - find ledger lines
  - not certain how many rows make the ledger lines
  - but consecutive large freqs indicate a ledger line,
  - also the first large drop off may indicate the end of ledger lines
  - since there are at least 5 ledger lines
  - first get the average of the first five.

- the largest deviation should be less than 20%;

- then you have 5 clusters of ledger lines

- next start working with stems.

- on example 11 - 18 cols have 93, 28+ have 92

- the avg and finding first drop off method works.
- next find which ranges equal what note.  map that shit out.
- start with the min
- min to min+4 are f

- between is e

- next to 9th is d

- next step:
- find where a stem "points to"
- find first non-ledger black point
- now lets collect the "boundaries" and analyze
  - unfortunately the 4 highest notes have redundant stems
  - four highest notes have a note that is laid out to right of stem (top of stem)
  - the rest of the notes have note laid out to left of stem (bottom of stem)
- normally we would check area right or left of the stem for the note, but it doesn't work out with half notes.  no "blackness" to check

- trick (all cases except the 1 px) find that one of the stems extends farther.  this is the side with the "bean".
- for 1 px case, must check diagonal from the tip
- lets first do this and print notes with Q just to check correctness.


- finally we must check for half notes