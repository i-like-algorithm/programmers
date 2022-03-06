/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   가장큰정사각형찾기_sejin.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:33:33 by sejpark           #+#    #+#             */
/*   Updated: 2021/09/14 14:34:05 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j]) {
                board[i][j] += min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (answer < board[i][j])
                answer = board[i][j];
        }
    }
    return answer * answer;
}
