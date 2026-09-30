# CONTRIBUTING

## Workflow

### One-time setup

1. `git clone git://g.csail.mit.edu/xv6-labs-2023`
2. `git remote rename origin mit`
3. `git remote add origin git@github.com:cosmo-grant/xv6-labs-2023.git`

### Working on a lab

1. `git checkout mit/<lab-name> -b <lab-name>`
2. commit lab work
3. `git push -u origin <lab-name>`

## What if `mit` upstream updates?

1. `git fetch mit`
2. for each updated branch:
  1. `git checkout <branch>`
  2. `git rebase mit/<branch>`
3. `git push origin <branch>`
