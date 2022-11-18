# <center>CS323 Assignment4</center>

**Name: Mingqian Liao**

**SID: 12012919**

## Exercise 1(Simple LR)

### Q1

**Augmented Grammar**
$$
S'\to S \ \ (1)
\\
S \to aB \ \ (2)
\\
B \to S * B \ \ (3)
\\
B \to \epsilon \ \ (4)
$$


#### Calculations of closures and GOTO targets

For $I_0$:
$$
S'\to ·S 
\\
S\to ·aB
$$
Let $I_1 = GOTO(I_0, S)$:
$$
S'\to S ·
$$
Let $I_2 = GOTO(I_0, a):$
$$
S\to a·B
\\
B\to ·S*B
\\
B \to ·
\\
S \to ·aB
$$
Let $I_3 = GOTO(I_2, B):$
$$
S\to aB·
$$
Let $I_4=GOTO(I_2,S):$
$$
B\to S· *B
$$
$GOTO(I_2, a)$ will still be $I_2$

Let $I_5 = GOTO(I_4, *):$
$$
B\to S*·B
\\
B\to ·S*B
\\
S \to ·aB
\\
B\to ·
$$
$GOTO(I_5, S)$ will go to $I_4$

$GOTO(I_5, a)$ will go to $I_2$

Let $I_6 = GOTO(I_5, B):$
$$
B\to S*B·
$$


#### Calculation of FIRST/FOLLOW

$$
FIRST(B) = \{\epsilon, a\}
\\
FIRST(S) = \{a\}
\\
FIRST(S') = \{a \}
\\
FOLLOW(S') = \{\$, *\}
\\
FOLLOW(S) = \{\$, *\}
\\
FOLLOW(B) = \{\$, * \}
$$

#### SLR(1) Table

| **STATE** | **ACTION** |       |       | **GOTO** |       |
| :-------: | :--------: | :---: | :---: | :------: | :---: |
|           |   **a**    | ***** | **$** |  **S**   | **B** |
|     0     |     s2     |       |       |    1     |       |
|     1     |            |       |  acc  |          |       |
|     2     |     s2     |  r4   |  r4   |    4     |   3   |
|     3     |            |  r2   |  r2   |          |       |
|     4     |            |  s5   |       |          |       |
|     5     |     s2     |  r4   |  r4   |    4     |   6   |
|     6     |            |  r3   |  r3   |          |       |

### Q2

Yes, since there is no conflict, it is an SLR(1) grammar.

### Q3

Yes.

| **Stack**     | **Symbol** | **Input** | **Action**                 |
| ------------- | ---------- | :-------- | -------------------------- |
| 0             | $          | aaaa***$  | shift to 2                 |
| 0 2           | $a         | aaa***$   | shift to 2                 |
| 0 2 2         | $aa        | aa***$    | shift to 2                 |
| 0 2 2 2       | $aaa       | a***$     | shift to 2                 |
| 0 2 2 2 2     | $aaaa      | ***$      | reduce by $B \to \epsilon$ |
| 0 2 2 2 2     | $aaaaB     | ***$      | GOTO 3                     |
| 0 2 2 2 2 3   | $aaaaB     | ***$      | reduce by $S\to aB$        |
| 0 2 2 2 4     | $aaaS      | ***$      | shift to 5                 |
| 0 2 2 2 4 5   | $aaaS*     | **$       | reduce by $B \to \epsilon$ |
| 0 2 2 2 4 5   | $aaaS*B    | **$       | GOTO 6                     |
| 0 2 2 2 4 5 6 | $aaaS*B    | **$       | reduce by $B \to S*B$      |
| 0 2 2 2 3     | $aaaB      | **$       | reduce by $S \to aB$       |
| 0 2 2 4       | $aaS       | **$       | shift to 5                 |
| 0 2 2 4 5     | $aaS*      | *$        | reduce by $B \to \epsilon$ |
| 0 2 2 4 5     | $aaS*B     | *$        | GOTO 6                     |
| 0 2 2 4 5 6   | $aaS*B     | *$        | reduce by $B \to S*B$      |
| 0 2 2 3       | $aaB       | *$        | reduce by $S \to aB$       |
| 0 2 4         | $aS        | *$        | shift to 5                 |
| 0 2 4 5       | $aS*       | $         | reduce by $B \to \epsilon$ |
| 0 2 4 5       | $aS*B      | $         | GOTO 6                     |
| 0 2 4 5 6     | $aS*B      | $         | reduce by $B \to S*B$      |
| 0 2 3         | $aB        | $         | reduce by $S \to aB$       |
| 0 1           | $S         | $         | acc                        |

## Exercise 2(Canonical LR)

### Q1

**Augmented Grammar**
$$
S'\to S \ \ (1)
\\
S \to aB \ \ (2)
\\
B \to S * B \ \ (3)
\\
B \to \epsilon \ \ (4)
$$

#### Calculation of FIRST/FOLLOW

$$
FIRST(B) = \{\epsilon, a\}
\\
FIRST(S) = \{a\}
\\
FIRST(S') = \{a \}
\\
FOLLOW(S') = \{\$, *\}
\\
FOLLOW(S) = \{\$, *\}
\\
FOLLOW(B) = \{\$, * \}
$$

#### Calculations of closures and GOTO targets

For $I_0:$

Since $FIRST(\$) = \{\$\}, FIRST(S\$) = \{a\}$

$I_0 = CLOSURE([S'\to ·S, \$]) = $
$$
[S'\to ·S, \$]
\\
[S\to ·aB, \$]
$$
$I_1 = GOTO(I_0, S) = CLOSURE(\{[S'\to S·,\$]\}) = \{[S'\to S·, \$]\}$

Since $FIRST(B) = \{\epsilon, a\}, FIRST(*B\$) = \{*\}$, $I_2 = GOTO(I_0, a) = CLOSURE(\{[S\to a·B, \$]\}) = $
$$
[S\to a·B, \$]
\\
[B\to ·S*B, \$]
\\
[B\to ·\epsilon, \$]
\\
[S \to ·aB, *]
$$
$I_3 = GOTO(I_2, B) = CLOSURE(\{[S\to aB·, \$]\})=  \{[S\to aB·, \$]\}$

$I_4 = GOTO(I_2, S) = CLOSURE(\{[B\to S·*B, \$]\}) = \{[B\to S·*B, \$]\}$

$I_5 = GOTO(I_2, a) = CLOSURE(\{[S\to a·B, *]\}) = $
$$
[S\to a · B, *]
\\
[B\to ·S * B, *]
\\
[B \to ·\epsilon, *]
\\
[S \to ·aB, *]
$$
$I_6 = GOTO(I_4, *) = CLOSURE(\{B\to S*·B, \$\}) = $
$$
[B\to S*·B, \$]
\\
[B\to·S*B, \$]
\\
[B\to ·\epsilon, \$]
\\
[S \to ·aB, *]
$$
$I_7 = GOTO(I_5, B) = CLOSURE(\{[S\to aB·, *]\}) = \{[S\to aB·, *]\}$

$I_8 = GOTO(I_5, S) = CLOSURE(\{[B\to S·*B, *]\}) = \{[B\to S·*B, *]\}$

Since $FIRST(*) = \{*\}$, $GOTO(I_5, a) = CLOSURE(\{[S\to a·B, *]\}) = I_5$

$GOTO(I_6, S) = CLOSURE(\{[B\to S·*B, \$]\}) = I_4$

$GOTO(I_6, a) = CLOSURE(\{[S\to a·B, *]\}) = I_5$

$I_9 = GOTO(I_6, B) = CLOSURE(\{[B \to S*B·, \$]\}) = \{[B\to S*B·,\$]\}$

$I_{10} = GOTO(I_8, *) = CLOSURE(\{[B\to S*·B, *]\}) = $
$$
[B\to S*·B, *]
\\
[B \to ·S*B, *]
\\
[B\to ·\epsilon, *]
\\
[S \to ·aB, *]
$$
$GOTO(I_{10}, B) = CLOSURE(\{[B\to S*B·, *]\}) = \{[B\to S*B·, *]\} = I_{11}$

$GOTO(I_{10}, S) = CLOSURE(\{[B\to S·*B, *]\}) = I_8$

$GOTO(I_{10}, a) = CLOSURE(\{[B\to a·B, *]\}) = I_5$

#### CLR Table

| **State** | **Action** |      |      | **GOTO** |      |
| --------- | ---------- | ---- | ---- | -------- | ---- |
|           | a          | *    | $    | S        | B    |
| 0         | s2         |      |      | 1        |      |
| 1         |            |      | acc  |          |      |
| 2         | s5         |      | r4   | 4        | 3    |
| 3         |            |      | r2   |          |      |
| 4         |            | s6   |      |          |      |
| 5         | s5         | r4   |      | 8        | 7    |
| 6         | s5         |      | r4   | 4        | 9    |
| 7         |            | r2   |      |          |      |
| 8         |            | s10  |      |          |      |
| 9         |            |      | r3   |          |      |
| 10        | s5         | r4   |      | 8        | 11   |
| 11        |            | r3   |      |          |      |

### Q2

Yes. Since there is no conflict in the table, it is an LR(1) grammar.

### Q3

Yes.

| **Stack**       | **Symbol** | **Input** | **Action**                 |
| --------------- | ---------- | --------- | -------------------------- |
| 0               | $          | aaaa***$  | shift to 2                 |
| 0 2             | $a         | aaa***$   | shift to 5                 |
| 0 2 5           | $aa        | aa***$    | shift to 5                 |
| 0 2 5 5         | $aaa       | a***$     | shift to 5                 |
| 0 2 5 5 5       | $aaaa      | ***$      | reduce by $B \to \epsilon$ |
| 0 2 5 5 5 7     | $aaaaB     | ***$      | reduce by $S \to aB$       |
| 0 2 5 5 8       | $aaaS      | ***$      | shift to 10                |
| 0 2 5 5 8 10    | $aaaS*     | **$       | reduce by $B \to \epsilon$ |
| 0 2 5 5 8 10 11 | $aaaS*B    | **$       | reduce by $B \to S*B$      |
| 0 2 5 5 7       | $aaaB      | **$       | reduce by$ S \to aB$       |
| 0 2 5 8         | $aaS       | **$       | shift to 10                |
| 0 2 5 8 10      | $aaS*      | *$        | reduce by $B \to \epsilon$ |
| 0 2 5 8 10 11   | $aaS*B     | *$        | reduce by $B \to S*B$      |
| 0 2 5 7         | $aaB       | *$        | reduce by $S \to aB$       |
| 0 2 4           | $aS        | *$        | shift to 6                 |
| 0 2 4 6         | $aS*       | $         | reduce by$ B \to \epsilon$ |
| 0 2 4 6 9       | $aS*B      | $         | reduce by$ B \to S*B$      |
| 0 2 3           | $aB        | $         | reduce by$ S \to aB$       |
| 0 1             | $S         | $         | acc                        |

## Exercise 3(LALR)

### Q1

**Augmented Grammar**
$$
S'\to S \ \ (1)
\\
S \to aB \ \ (2)
\\
B \to S * B \ \ (3)
\\
B \to \epsilon \ \ (4)
$$


There are five pairs that can be merged in the augmented grammar.

We can replace the $I_2, I_5$ with the union of them: 

==$I_{25} = $==
$$
[S\to a·B, \$/*]
\\
[B\to ·S*B, \$/*]
\\
[B\to ·\epsilon, \$/*]
\\
[S \to ·aB, *]
$$
We can replace the $I_6, I_{10}$ with the union of them, too:

==$I_{610} = $==
$$
[B\to S*·B, \$/*]
\\
[B\to·S*B, \$/*]
\\
[B\to ·\epsilon, \$/*]
\\
[S \to ·aB, *]
$$
==$I_{37} = \{[S\to aB·, \$/*]\}$==

==$I_{48} = \{[B\to S·*B, \$/*]\}$==

==$I_{911} = \{[B\to S*B·, \$/*]\}$==

#### LALR Table

| **State** | **Action** |      |      | **GOTO** |           |
| --------- | ---------- | ---- | ---- | -------- | --------- |
|           | a          | *    | $    | S        | B         |
| 0         | s25        |      |      | 1        |           |
| 1         |            |      | acc  |          |           |
| 25        | s25        | r4   | r4   | $I_{48}$ | $I_{37}$  |
| 37        |            | r2   | r2   |          |           |
| 48        |            | s610 |      |          |           |
| 610       | s25        | r4   | r4   | $I_{48}$ | $I_{911}$ |
| 911       |            | r3   | r3   |          |           |

### Q2

Yes, since there is no conflict in the table.

### Q3

Yes

| **Stack**             | **Symbol** | **Input** | **Action**                 |
| --------------------- | ---------- | --------- | -------------------------- |
| 0                     | $          | aaaa***$  | shift to 25                |
| 0 25                  | $a         | aaa***$   | shift to 25                |
| 0 25 25               | $aa        | aa***$    | shift to 25                |
| 0 25 25 25            | $aaa       | a***$     | shift to 25                |
| 0 25 25 25 25         | $aaaa      | ***$      | reduce by $B \to \epsilon$ |
| 0 25 25 25 25 37      | $aaaaB     | ***$      | reduce by $S \to aB$       |
| 0 25 25 25 48         | $aaaS      | ***$      | shift to 610               |
| 0 25 25 25 48 610     | $aaaS*     | **$       | reduce by $B \to \epsilon$ |
| 0 25 25 25 48 610 911 | $aaaS*B    | **$       | reduce by$ B \to S*B$      |
| 0 25 25 25 37         | $aaaB      | **$       | reduce by$ S \to aB$       |
| 0 25 25 48            | $aaS       | **$       | shift to 610               |
| 0 25 25 48 610        | $aaS*      | *$        | reduce by $B \to \epsilon$ |
| 0 25 25 48 610 911    | $aaS*B     | *$        | reduce by $B \to S*B$      |
| 0 25 25 37            | $aaB       | *$        | reduce by $S \to aB$       |
| 0 25 48               | $aS        | *$        | shift to 610               |
| 0 25 48 610           | $aS*       | $         | reduce by $B \to \epsilon$ |
| 0 25 48 610 911       | $aS*B      | $         | reduce by $B \to S*B$      |
| 0 25 37               | $aB        | $         | reduce by $S \to aB$       |
| 0 1                   | $S         | $         | acc                        |
