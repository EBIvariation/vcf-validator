Contributing to vcf-validator
==========================

We welcome community contributions to vcf-validator! To build tool locally, follow the instructions in the [README.md file](https://github.com/EBIvariation/vcf-validator/blob/master/README.md).


## First Timers Welcome!

New to open source? Here is a selection of issues we've made especially for first-timers. Follow this [link](https://github.com/EBIvariation/vcf-validator/issues?q=is%3Aissue+is%3Aopen+label%3Abeginner).


## Making a New PR
Once you found an interesting issue to work on you may check if someone other is not working on the same issue. You can ask once in the issue to get that issue assigned to you. Once you get an approval go for the PR. While making a new PR do follow these norms:

-  Fetch the latest changes by `git fetch upstream`.
-  Update the local develop branch `git rebase upstream/develop develop`.
-  Create a new branch from develop `git checkout -b <branch_name> develop`.
-  Add and commit the changes, commit messages should be short and well explanatory.
-  While creating new PR, change the base from master to develop.
-  PR message should be well explanatory and should contain reference to the issue this PR is for.
-  Once the PR is ready for a review, ask for a review.

## Coding Practice
There are some coding practices that we follow to make code easily readable and modifiable. Few of them that should be kept in mind while coding are:

- Consistent Indentation - We generally prefer 4 spaces for indentation.
- Comments & Documentation - Provide comments whenever required, so that it may be easy for other developers to read your code. Also avoid obvious comments.
- Tests - Add tests if new functionality is added to ensure that this functionality does not break in future.
- Consistent Naming Scheme - Follow a consistent naming scheme. We prefer `snake_case`(underscored) instead of `camelCase`. Naming of variables should be done in well explanatory way.
- DRY Principle - Every piece of knowledge must have a single, unambiguous, authoritative representation within a system. Aslo called [Don't repeat yourself](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself)
- Avoid Deep Nesting - Too many levels of nesting make code harder to read.
- Limit Line Length - It is a good practice to avoid writing horizontally long lines of code. There is no such limit but still having max lenght till 80 is good practice. For more follow this [link](https://stackoverflow.com/a/111009/6799074).
- Bracket Style - We generally use attached brackets for `conditions` and `loops` and broken brackets for `functions` and `classes`. Our style is a variant of [K&R style : variant](https://en.wikipedia.org/wiki/Indentation_style#K&R), difference is that we force use of brackets even if there is single statement in the brackets.

## Bug reports & troubleshooting

If you are submitting a bug, please go to [this link](https://github.com/EBIvariation/vcf-validator/issues/new)
