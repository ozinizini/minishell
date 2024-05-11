/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozini <ozini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:33:59 by ozini             #+#    #+#             */
/*   Updated: 2023/11/30 12:09:04 by ozini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* int main() {
    char lowercase = 'H';
    char nonAlphabetic = '$';
    char alreadyUppercase = 'Z';

    // Convert a lowercase letter to uppercase
    char uppercase = tolower(lowercase);
    printf("Original: %c, Uppercase: %c\n", lowercase, uppercase);

    // Non-alphabetic character remains unchanged
    char unchanged = tolower(nonAlphabetic);
    printf("Original: %c, Unchanged: %c\n", nonAlphabetic, unchanged);

    // Uppercase letter remains unchanged
    char unchangedUppercase = tolower(alreadyUppercase);
    printf("Original: %c, Unchanged: %c\n", 
	alreadyUppercase, unchangedUppercase);

    printf("A partir de aquí están los resultados con mi función \n");
    
    // Convert a lowercase letter to uppercase
    uppercase = ft_tolower(lowercase);
    printf("Original: %c, Uppercase: %c\n", lowercase, uppercase);

    // Non-alphabetic character remains unchanged
    unchanged = ft_tolower(nonAlphabetic);
    printf("Original: %c, Unchanged: %c\n", nonAlphabetic, unchanged);

    // Uppercase letter remains unchanged
    unchangedUppercase = ft_tolower(alreadyUppercase);
    printf("Original: %c, Unchanged: %c\n", 
	alreadyUppercase, unchangedUppercase);

    return 0;
} */
